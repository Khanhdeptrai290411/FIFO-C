#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    int numbers[7];
    int sum = 0;

    printf("Waiting for data...\n");

    // Mở FIFO ở chế độ đọc
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO");
        exit(1);
    }

    // Đọc các số từ FIFO
    read(fd, numbers, sizeof(numbers));
    printf("Received numbers: ");
    for (int i = 0; i < 7; i++) {
        sum += numbers[i];
        printf("%d ", numbers[i]);
    }
    printf("\nSum: %d\n", sum);

    close(fd);
    return 0;
}
