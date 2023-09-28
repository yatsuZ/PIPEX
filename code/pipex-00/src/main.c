/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:59:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/28 17:23:11 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

int	main(int ac, char **av, char **env)
{
	// char	*path;
	pid_t	pid;
	int		status;

	pid = fork();
	// ft_printf("%s\n", find_path(env));
	// if (ac == 2)
	// 	path = ft_strjoin("./", av[1]);
	// else
	// 	path = av[1];
	// if (!access(path, F_OK))
	// {
	// 	ft_printf("BON CHEMIN\n");
	// }
	if (!pid)
		execve("./test.sh", ft_split(av[1], ' '), env);
	ft_printf("pid = %d\n", pid);
	ft_printf("pergningiv\n");
	waitpid(-1, &status, 0);
	if (WIFEXITED(status)) {
	    int exit_status = WEXITSTATUS(status);
	    printf("Le script s'est terminé avec le code de retour : %d\n", exit_status);
	}
	return (0);
}

// int main(int argc, char **argv, char **envp) {
//     if (argc != 2) {
//         printf("Usage: %s <script.sh>\n", argv[0]);
//         return 1;
//     }

//     pid_t pid;
//     int status;

//     // Créer un processus enfant
//     pid = fork();

//     if (pid == -1) {
//         perror("fork");
//         return 1;
//     } else if (pid == 0) {
//         // Nous sommes dans le processus enfant
//         char *scriptPath = argv[1];

//         // Exécuter le script shell avec execve
//         if (execve(scriptPath, argv, envp) == -1) {
//             perror("execve");
//             return 1;
//         }
//     } else {
//         // Nous sommes dans le processus parent
//         // Attendre que le processus enfant se termine
//         waitpid(pid, &status, 0);

//         if (WIFEXITED(status)) {
//             int exit_status = WEXITSTATUS(status);
//             printf("Le script s'est terminé avec le code de retour : %d\n", exit_status);
//         }
//     }

//     return 0;
// }