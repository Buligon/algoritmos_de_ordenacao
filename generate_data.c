#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int inputs[] = {1, 100000, 2, 100000, 3, 100000, 1, 200000, 2, 200000, 3, 200000,
                    1, 300000, 2, 300000, 3, 300000, 1, 500000, 2, 500000, 3, 500000,
                    1, 1000000, 2, 1000000, 3, 1000000};

    const char *command = "generate_data.exe";

    int numInputs = sizeof(inputs) / sizeof(inputs[0]), i;

    for (i = 0; i < numInputs; i += 2) {
        char cmd[100];
        sprintf(cmd, "%s %d %d", command, inputs[i], inputs[i + 1]);

        int ret = system(cmd);

        if (ret != 0) {
            printf("Erro ao rodar comando: %s\n", cmd);
            return 1;
        }
    }

    return 0;
}
