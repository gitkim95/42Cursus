#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#endif

/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock


bonus
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink

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



*/