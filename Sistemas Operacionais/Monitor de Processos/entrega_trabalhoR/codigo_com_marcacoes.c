
#define _WIN32_WINNT 0x0600 // [01:12] Aqui eu explico sobre habilitar recursos a partir do Windows Vista

#include <windows.h>        // [02:01] Biblioteca principal para acessar funcao do sistema
#include <tlhelp32.h>       // [02:08] Usada para tirar snapshots dos processos
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>
#include <stdint.h>         // [02:30] Para usar tipos inteiros como uint64_t

#pragma comment(lib, "psapi.lib") // [03:05] Inclusao da biblioteca necessaria para metricas de processos

// [03:20] Funcao que obtem o tempo total de CPU usado pelo sistema
uint64_t get_system_cpu_time() {
    FILETIME ftIdle, ftKernel, ftUser;
    if (!GetSystemTimes(&ftIdle, &ftKernel, &ftUser)) {
        return 0;
    }
    ULARGE_INTEGER kernel, user;
    kernel.LowPart = ftKernel.dwLowDateTime;
    kernel.HighPart = ftKernel.dwHighDateTime;

    user.LowPart = ftUser.dwLowDateTime;
    user.HighPart = ftUser.dwHighDateTime;

    return (kernel.QuadPart - ((ULARGE_INTEGER){ftIdle.dwLowDateTime, ftIdle.dwHighDateTime}).QuadPart) + user.QuadPart;
}

// [04:20] Funcao para obter tempo de CPU de um processo especifico
uint64_t get_process_cpu_time(HANDLE hProcess) {
    FILETIME ftCreation, ftExit, ftKernel, ftUser;
    if (!GetProcessTimes(hProcess, &ftCreation, &ftExit, &ftKernel, &ftUser)) {
        return 0;
    }
    ULARGE_INTEGER kernel, user;
    kernel.LowPart = ftKernel.dwLowDateTime;
    kernel.HighPart = ftKernel.dwHighDateTime;

    user.LowPart = ftUser.dwLowDateTime;
    user.HighPart = ftUser.dwHighDateTime;

    return kernel.QuadPart + user.QuadPart;
}

// [05:15] Funcao principal que lista todos os processos com uso de CPU
void listar_processos_com_cpu() {
    HANDLE hSnapshot;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    DWORD pids[1024];
    TCHAR names[1024][MAX_PATH];
    uint64_t proc_cpu_times_samples[1024][3];
    uint64_t sys_cpu_times_samples[3];
    int count = 0;

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        printf("Erro ao tirar snapshot dos processos.\n");
        return;
    }
    if (!Process32First(hSnapshot, &pe32)) {
        printf("Erro ao obter processos.\n");
        CloseHandle(hSnapshot);
        return;
    }

    do {
        pids[count] = pe32.th32ProcessID;
        _tcsncpy(names[count], pe32.szExeFile, MAX_PATH);
        count++;
        if (count >= 1024) break;
    } while (Process32Next(hSnapshot, &pe32));
    CloseHandle(hSnapshot);

    const int samples = 3;
    const int wait_ms = 2000;

    for (int s = 0; s < samples; s++) {
        sys_cpu_times_samples[s] = get_system_cpu_time();

        for (int i = 0; i < count; i++) {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pids[i]);
            if (hProcess) {
                proc_cpu_times_samples[i][s] = get_process_cpu_time(hProcess);
                CloseHandle(hProcess);
            } else {
                proc_cpu_times_samples[i][s] = 0;
            }
        }

        if (s < samples - 1) {
            Sleep(wait_ms);
        }
    }

    printf("\n%-8s %-30s %-15s %%CPU\n", "PID", "Nome", "Memoria (KB)");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pids[i]);
        if (!hProcess) continue;

        PROCESS_MEMORY_COUNTERS pmc;
        SIZE_T memoriaKB = 0;
        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
            memoriaKB = pmc.WorkingSetSize / 1024;
        }
        CloseHandle(hProcess);

        double cpu_sum = 0.0;
        for (int s = 1; s < samples; s++) {
            uint64_t proc_delta = proc_cpu_times_samples[i][s] - proc_cpu_times_samples[i][s - 1];
            uint64_t sys_delta = sys_cpu_times_samples[s] - sys_cpu_times_samples[s - 1];

            SYSTEM_INFO sysinfo;
            GetSystemInfo(&sysinfo);

            double cpu_percent = 0.0;
            if (sys_delta > 0) {
                cpu_percent = ((double)proc_delta / (double)sys_delta) * 100.0 * sysinfo.dwNumberOfProcessors;
                if (cpu_percent > 100.0) cpu_percent = 100.0;
            }
            cpu_sum += cpu_percent;
        }
        double cpu_avg = cpu_sum / (samples - 1);

        _tprintf(TEXT("%-8u %-30s %-15zu %6.2f\n"), pids[i], names[i], memoriaKB, cpu_avg);
    }
}

// [11:40] Funcao auxiliar para encerrar processos por PID
void encerrar_processo() {
    DWORD pid;
    printf("Digite o PID do processo para encerrar: ");
    scanf("%lu", &pid);

    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
    if (hProcess == NULL) {
        printf("Nao foi possÃ­vel abrir o processo com PID %lu.\n", pid);
        return;
    }
    if (!TerminateProcess(hProcess, 0)) {
        printf("Falha ao encerrar o processo com PID %lu.\n", pid);
    } else {
        printf("Processo com PID %lu encerrado com sucesso.\n", pid);
    }
    CloseHandle(hProcess);
}

// [13:05] Funcao principal com menu interativo
int main() {
    int opcao = -1;
    while (opcao != 0) {
        printf("\n========== MONITOR DE PROCESSOS ==========\n");
        printf("1. Listar processos (PID, Nome, Memoria, %%CPU)\n");
        printf("2. Encerrar processo por PID\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_processos_com_cpu(); // [13:25] Chamada da listagem
                break;
            case 2:
                encerrar_processo();       // [13:50] Chamada da funcao de encerramento
                break;
            case 0:
                printf("Saindo...\n");     // [14:05]
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
    return 0;
}



//Sobre a parte da execução do código , continua nos prints do projeto.
