#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 512

int main() {
    int segment_id = shmget(IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR);
    char *shared_memory_write = (char *)shmat(segment_id, NULL, 0);
    int pid;

    printf("segment id: %d\n", segment_id);
    printf("memory address: %p\n", shared_memory_write);


    if((pid=fork())==0){
        printf("enter which u wanna shared: ");
        scanf("%s", shared_memory_write);
        printf("in child:\n");
        printf("writing to shared memory: %s\n", shared_memory_write);
        shmdt(shared_memory_write);
//        shmctl(); //todo: this function need three argument but in lesson plan said need nothing!

    }else{
        wait(NULL);
        printf("in father:\n");
        printf("now we read data from shared memory\n");
        char *shared_memory_read = (char *)shmat(segment_id, NULL, 0);
        printf("reading from shard memory: %s", shared_memory_read);
    }
    return 0;
}
