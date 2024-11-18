#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#endif

/*
memset
#include <string.h>
void	*memset(void *ptr, int value, size_t num);
ptr : 값을 설정할 메모리 블록의 시작 주소의 포인터
value : 메모리 블록에 채울 값, 실제론 unsigned char로 변환 됨
num : 설정할 바이트 수

printf
#include <stdio.h>

malloc
free
#include <stdlib.h>

write
#include <unistd.h>

usleep
#include <unistd.h>
int		usleep(useconds_t microseconds);
microseconds : 대기 시간을 마이크로초 단위로 지정, 1초는 1,000,000 마이크로초
현재 실행 중인 프로세스를 일시정지하는 함수
성공 시 0 반환, 실패 시 -1 반환, errno 설정

gettimeofday
#include <sys/time.h>
int		gettimeofday(struct timeval *tv, struct timezone *tz);
tv : 현재 시간을 저장할 timeval 구조체의 포인터
	- tv_sec : 초 단위로 나타낸 시간 (1970년 1월 1일부터 현재까지의 초)
	- tv_usec : 마이크로초 단위로 나타낸 시간 (0에서 999,999 사이의 값)
tz : 현재 로컬 시간대에 대한 정보를 담고 있는 timezone 구조체의 포인터
	- NULL 전달이 일반적
현재 시간을 반환하는 함수, 주로 시간 측정 및 시간 차이를 계산할 때 쓰임
성공 시 0 반환, 실패 시 -1 반환, errno 설정

pthread_create
#include <pthread.h>
int		pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
thread : 생성될 스레드의 ID를 저장할 변수에 대한 포인터
attr : 스레드의 속성을 지정하는 pthread_attr_t 구조체에 대한 포인터
	- NULL 전달 시 기본 속성 사용
start_routine : 새로 생성된 스레드가 실행할 함수
	- 사용 함수는 void *타입의 인수를 받으며, void *타입의 값을 반환해야 한다
arg : start_routine 함수에 전달할 인수
	- void *형식으므로 원하는 데이터 타입을 포인터로 전달 가능하다.
POSIX 스레드를 생성하는 함수, 새로운 스레드를 시작할 때 사용된다.
스레드 실행을 위한 기본 설정을 하며, 스레드를 병렬로 실행할 수 있게 한다.
스레드 종료 후 pthread_join으로 메인 스레드가 종료를 기다리도록 해서 자원 회수해야한다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

pthread_detach
#include <pthread.h>
int		pthread_detach(pthread_t thread);
thread : 분리할 스레드의 ID를 나타내는 변수, 이 스레드는 이제 분리된 상태로 실행된다.
POSIX 스레드에서 분리된 스레드를 만드는 함수, 분리된 스레드는 종료된 후 자동으로 자원을 해제한다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

pthread_join
#include <pthread.h>
int		pthread_join(pthread_t thread, void **retval);
thread : 종료를 기다릴 스레드의 ID, pthread_create로 생성된 스레드여야 한다.
retval : 종료된 스레드의 반환 값을 받을 포인터, 그 값이 필요가 없다면 NULL을 전달한다.
POSIX 스레드가 종료될 떄까지 대기하는 함수
이 함수를 호출하는 스레드는 대상 스레드가 종료될 때까지 대기하고 리소스를 회수할 수 있다.
멀티스레딩 프로그램에서 여러 스레드의 실행을 동기화 할떄 사용된다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

pthread_mutex_init
#include <pthread.h>
int		pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
mutex : 초기화할 mutex 객체에 대한 포인터
attr : mutex 속성에 대한 포인터
	- NULL 전달 시 기본 속성으로 초기화할 수 있다.
mutex 객체를 초기화하는 함수
mutex는 상호 배제 기법을 사용하여 여러 스레드가 동시에 공유자원에 접근하는 것을 제어한다.
새로운 mutex 객체를 생성하고, 이를 초기화하여 스레드 간 동기화를 가능하게 한다.
race condition을 방지하는데에 필요하다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

pthread_mutex_destroy
#include <pthread.h>
int		pthread_mutex_destroy(pthread_mutex_t *mutex);
mutex 객체를 파괴하는 함수
init/ lock/ unlock으로 사용한 mutex를 더 이상 사용하지 않을 떄 호출하여 리소스 해제를 해준다.
잠겨있으면 안되며 모든 스레드에서 unlock이 되어있어야 한다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

pthread_mutex_lock
#include <pthread.h>
int		pthread_mutex_lock(pthread_mutex_t *mutex);
mutex를 잠그는 함수
init으로 초기화가 되어있어야 한다
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정
	- 실패 시 mutex가 다른 스레드에 의해 이미 잠겨있을 경우 해당 스레드는 mutex가 해제될 때까지 대기

pthread_mutex_unlock
#include <pthread.h>
int		pthread_mutex_unlock(pthread_mutex_t *mutex);
mutex를 잠금 해제하는 함수
다른 스레드가 해당 mutex를 사용할 수 있도록 한다.
성공 시 0 반환, 실패 시 오류 코드 반환, errno 설정

bonus

memset - mand
printf - mand
malloc - mand
free - mand
write - mand
pthread_create - mand
pthread_detach - mand
pthread_join - mand
usleep - mand
gettimeofday - mand

fork
#include <unistd.h>

kill - minishell
#include <signal.h>

exit
#include <stdlib.h>

waitpid
#include <sys/wait.h>

sem_open
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
sem_t	*sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
name : 세마포어의 이름을 지정하는 문자열
	- 이름은 '/'로 시작해야 하며, 파일 시스템의 경로처럼 이름을 지정
	- 이름은 고유해야 하며, 동일한 이름을 가진 세마포어는 다른 프로세스에서 공유될 수 있다.
oflag : 세마포어를 열 때 사용할 플래그
	- O_CREAT: 세마포어가 존재하지 않으면 새로 생성합니다.
	- O_EXCL: O_CREAT와 함께 사용되며, 이미 존재하는 세마포어가 있으면 오류를 반환합니다.
	- O_RDWR: 세마포어를 읽고 쓸 수 있는 권한으로 엽니다.
mode : 세마포어의 권한을 지정하는 값
	- O_CREAT 플래그를 사용할 때만 유효하며, 파일의 권한과 동일하게 설정 가능
	- S_IRUSR | S_IWUSR는 읽기와 쓰기 권한을 나타낸다.
value : 새로 생성되는 세마포어의 초기 값
	- 세마포어가 관리할 자원의 수를 나타낸다. 주로 0 이상
	- 1로 설정 시 이진 세마포어가 된다.
세마포어를 생성하거나 열기 위한 함수
POSIX 시스템에서 프로세스간의 동기화와 상호 배제를 위해 사용
성공 시 sem_t *타입의 세마포어 객체 포인터를 반환, 이후 sem_wait(), sem_post()에서 사용
실패 시 SEM_FAILED를 반환하고 errno 설정

sem_close
#include <semaphore.h>
int		sem_close(sem_t *sem);
sem : 세마포어 객체를 가리키는 포인터, sem_open()으로 생성된 세마포어에서 반환된 포인터여야 한다.
세마포어 객체를 닫는 함수
세마포어를 실제로 삭제하지는 않고, 참조만 종료하는 역할
성공 시 0 반환, 실패 시 -1 반환, errno 설정

sem_post
#include <semaphore.h>
int		sem_post(sem_t *sem);
sem : 세마포어 객체를 가리키는 포인터, sem_open()으로 생성된 세마포어에서 반환된 포인터여야 한다.
	- 이 세마포어 객체는 다른 프로세스나 스레드에서 공유될 수 있다.
세마포어를 증가시키는 함수
세마포어의 값을 1을 증가시켜, 세마포어가 나타내는 자원에 대한 접근을 다른 프로세스나 스레드에게 허용
세마포어는 자원의 수를 추적하는 데 사용되며, sem_post()는 자원을 반납하거나 사용 가능하게 만든다.
성공 시 0 반환, 실패 시 -1 반환, errno 설정

sem_wait
#include <semaphore.h>
int		sem_wait(sem_t *sem);
sem : 세마포어 객체를 가리키는 포인터, sem_open()으로 생성된 세마포어에서 반환된 포인터여야 한다.
	- 이 세마포어 객체는 다른 프로세스나 스레드에서 공유될 수 있다.
세마포어를 대기(잠금)하는 함수
세마포어의 값을 1을 감소시켜, 세마포어가 관리하는 자원을 획득하려는 포로세스나 스레드가 자원을 사용할 수 있도록 한다.
만약 세마포어의 값이 0이라면 sem_wait()는 세마포어 값이 0에서 1로 증가할 때까지 대기한다.
**이는 자원이 사용 중일 때 다른 프로세스나 스레드가 자원을 사용할 수 없도록 하는 역할을 한다.
성공 시 0 반환, 실패 시 -1 반환, errno 설정

sem_unlink
#include <semaphore.h>
int		sem_unlink(const char *name);
name : 삭제할 세마포어의 이름을 지정하는 문자열, 이 이름은 sem_open()을 사용하여 세마포어를 생성할 때 지정한 이름과 일치해야 한다.
이름이 지정된 세마포어를 삭제하는 함수
세마포어를 시스템에서 완전히 제거하는 데 사용된다.
사용 중인 세마포어의 경우 다른 프로세스가 사용을 마친 후 삭제된다.
이름이 없는 세마포어에는 사용하지 못한다.
성공 시 0 반환, 실패 시 -1 반환, errno 설정

다음은 이 과제를 성공적으로 수행하기 위해 알아야 할 사항입니다:

• 한 명 이상의 철학자가 원탁에 앉아 있습니다.
• 탁자 중앙에는 큰 스파게티 그릇이 있습니다.

• 철학자들은 번갈아 가며 먹거나, 생각하거나, 잠을 잡니다.
• 먹고 있을 때는 생각하거나 잠을 자지 않습니다.
• 생각하고 있을 때는 먹거나 잠을 자지 않습니다.
• 잠을 자고 있을 때는 먹거나 생각하지 않습니다.

• 탁자에는 포크가 있습니다. 철학자 수만큼 포크가 있습니다.

• 스파게티를 한 개의 포크로 먹는 것은 매우 불편하므로, 철학자는 왼쪽과 오른쪽 포크를 각각 하나씩 들어서 먹습니다.
• 철학자가 식사를 마친 후에는 포크를 다시 탁자에 놓고 잠을 잡니다. 잠에서 깨어나면 다시 생각을 시작합니다. 시뮬레이션은 철학자가 굶어 죽으면 종료됩니다.

• 모든 철학자는 반드시 먹어야 하며 굶어 죽지 않아야 합니다.

• 철학자들은 서로 대화하지 않습니다.

• 철학자들은 다른 철학자가 죽어가고 있다는 것을 알지 못합니다.

• 철학자가 죽는 것은 피해야 한다는 것은 당연한 일입니다!

• 전역 변수는 금지됩니다!

• 프로그램은 다음과 같은 인자를 받아야 합니다:
	• number_of_philosophers: 철학자의 수 (그리고 포크의 수)
	• time_to_die (밀리초 단위): 철학자가 마지막 식사 후 time_to_die 밀리초 동안 음식을 시작하지 않으면 죽습니다.
	• time_to_eat (밀리초 단위): 철학자가 음식을 먹는 데 걸리는 시간. 이 동안 철학자는 두 개의 포크를 사용해야 합니다.
	• time_to_sleep (밀리초 단위): 철학자가 잠자는 시간.
	• number_of_times_each_philosopher_must_eat (선택적 인자): 모든 철학자가 적어도 number_of_times_each_philosopher_must_eat 번은 먹으면 시뮬레이션이 종료됩니다. 지정되지 않으면 시뮬레이션은 철학자가 죽을 때 종료됩니다.
• 각 철학자는 1번부터 number_of_philosophers까지 번호를 가집니다.
• 철학자 번호 1은 철학자 번호 number_of_philosophers와 옆에 앉아 있습니다. 다른 철학자 번호 N은 철학자 번호 N-1과 N+1 사이에 앉습니다.

• 철학자의 상태 변화는 다음과 같은 형식으로 출력해야 합니다:
	• timestamp_in_ms X has taken a fork
	• timestamp_in_ms X is eating
	• timestamp_in_ms X is sleeping
	• timestamp_in_ms X is thinking
	• timestamp_in_ms X died
• 여기서 timestamp_in_ms는 현재 밀리초 단위로 측정된 타임스탬프이며, X는 철학자의 번호입니다.

• 상태 변경 메시지는 다른 메시지와 섞이지 않도록 해야 합니다.

• 철학자가 죽었다는 메시지는 철학자가 실제로 죽은 시점으로부터 최대 10 밀리초 이내에 출력되어야 합니다.

• 다시 한 번 강조하지만, 철학자들은 죽지 않도록 해야 합니다!

필수 부분에 대한 구체적인 규칙은 다음과 같습니다:
• 각 철학자는 하나의 스레드여야 합니다.
• 철학자들 간에 각기 하나씩 포크가 있습니다. 따라서 여러 철학자가 있을 경우, 각 철학자는 왼쪽과 오른쪽에 각각 하나의 포크를 가지고 있습니다. 만약 철학자가 한 명뿐이라면, 테이블에는 포크가 하나만 있어야 합니다.
• 철학자들이 포크를 중복으로 사용하는 것을 방지하기 위해, 각 포크의 상태는 해당 포크에 대한 뮤텍스를 사용하여 보호해야 합니다.

보너스
• 모든 포크는 테이블 중앙에 놓입니다.
• 포크는 메모리에서 상태를 가지지 않으며, 사용 가능한 포크의 수는 세마포어로 표시됩니다.
• 각 철학자는 하나의 프로세스여야 합니다. 그러나 메인 프로세스는 철학자가 되어서는 안 됩니다.
*/