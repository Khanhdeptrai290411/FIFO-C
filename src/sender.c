#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    int numbers[7];

    // Mở FIFO ở chế độ ghi
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open FIFO");
        exit(1);
    }

    // Sinh ngẫu nhiên các số nguyên
    srand(time(NULL));
    printf("Sending numbers: ");
    for (int i = 0; i < 7; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Ghi các số vào FIFO
    write(fd, numbers, sizeof(numbers));
    close(fd);

    return 0;
}
