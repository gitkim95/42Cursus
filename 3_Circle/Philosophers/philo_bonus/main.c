#include "philo_bonus.h"

int	main()
{
	int idx = 0;
	while (idx < 5)
	{
		ph_delete_sem(NULL, 'n', idx);
		ph_delete_sem(NULL, 'd', idx);
		ph_delete_sem(NULL, 't', idx);
		ph_delete_sem(NULL, 'f', idx);
		idx++;
	}
	sem_unlink("/p0");
}