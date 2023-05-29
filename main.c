/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.d                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:25 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/28 00:04:39 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 항상 나침반 -- 반향으로 사용할 것.

// int main(int ac, char *av[])
// {
//     // deq 구조체를 담는 변수 a, b 인스턴스화
//     // 어떤 자료구조 유리한지 - 선택이유
//     t_deq deq_a;
//     t_deq deq_b;

//     // argument 유효성 체크 부분
//     if (ac < 2)
//         return (0);
//     /* if(valid_input(av) == 0)
//          error(); // error함수 호출 */
 
//     // 두 deq 초기세팅
// 	// 초기화 <- 인수를 넣어 deq 구성한다는 의미
//     deq_a = configuration_deq(ac, av);
//     deq_b = NULL;

//     // deq_a의 크기 구하기 <- 정렬 전.
//     deq_a->a_size = get_deq_a_size(deq_a);
//     deq_b->b_size = get_deq_b_size(deq_b);

// 	// 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

//     // 정렬알고리즘 사용 정렬부분.
//     sort(deq_a, deq_b);

//     // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
//     free_deq(deq_a);
//     free_deq(deq_b);

//     return (0);
// }
// void check_leak(void)
// {
//     system("leaks push_swap");
// }

#include <stdio.h>
int main(int ac, char **av)
{
    // atexit(check_leak);
	// deq 구조체를 담는 변수 a, b 인스턴스화
    // 어떤 자료구조 유리한지 - 선택이유
    t_deq* deq_a;
    t_deq* deq_b;


    // argument 유효성 체크 부분'
    // if (ac == 1)
    //     return (0);
    // ac = 2;

    // char tmp[2][7] = {"a.out", ""};
    // av = (char**)tmp;
    // if (ac == 1 && ++(*av) == NULL)
    // {
    //     ft_error();
    //     return(0);
    // }
    // if (ac < 2)
    //     ft_error();

    if (ac < 2)
        return (0);
    if (!*av[1])
        return (0);
    // check_args(ac, av)
    // {
    //     if (ac < 2)
    //         exit(0);
    //     if (!*av[1])
    //         exit(0)
    // }

	deq_a = parse(ac,av,1);
    deq_b = malloc_deq_b();
    // deq_b = NULL;

	if(check_duplicate_arg(deq_a) == 1)
	{
		ft_free_deq_a(deq_a);
        ft_free_deq_b(deq_b);
		ft_error();
	}

    deq_a->a_size = get_deq_a_size(deq_a);

    deq_a->arr =(int *)malloc(sizeof(int) * deq_a->a_size);

    int i = 0;
   
    t_node *temp = deq_a->a_top;
    
    while (temp)
    {
        deq_a->arr[i++] = temp->content;
        temp = temp->next;
    }
    

    content_trans_idx(deq_a);


    sort(deq_a, deq_b);


     if (!check_sort(deq_a))
         last_setting_deque(deq_a);
    


    // deq_print(deq_a);


    // deq_print(deq_b);

    ft_free_deq_a(deq_a);
    ft_free_deq_b(deq_b);   

    //system("leaks push_swap");
    return (0);

    // // deq_a의 크기 구하기 <- 정렬 전.
    // deq_a->a_size = ft_deq_size(deq_a);
	
	// // 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

    // // 정렬알고리즘 사용 정렬부분.
    // sort(deq_a, deq_b);

    // // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
    // free_deq(deq_a);
    // free_deq(deq_b);
}


















// int main()
// {
//     t_deq deq_a;
//     t_deq deq_b;
//     t_node* node;



//     init_deq(&deq_a);
//     init_deq(&deq_b);

//     node = init_node(2);
//     push_bot_a(&deq_a, node);

//     node = init_node(30);
//     push_bot_a(&deq_a, node);

//     node = init_node(50000);
//     push_bot_a(&deq_a, node);

//     node = init_node(-42304);
//     push_bot_a(&deq_a, node);
    

//     node = init_node(-710);
//     push_bot_a(&deq_a, node);

//     node = init_node(-320);
//     push_bot_a(&deq_a, node);

//     node = init_node(11);
//     push_bot_a(&deq_a, node);

//     node = init_node(-31);
//     push_bot_a(&deq_a, node);

//     // 이 경우 뭐지? -- 에러, 에러를 잘, 잘 찾을 것
//     node = init_node(41);
//     push_bot_a(&deq_a, node);

//     node = init_node(-1);
//     push_bot_a(&deq_a, node);

//     node = init_node(-13);
//     push_bot_a(&deq_a, node);

//     node = init_node(-2);
//     push_bot_a(&deq_a, node);

// /*
// a_top data : 4
// a_top data : 1
// a_top data : 9
// a_top data : 7
// a_top data : 2
// a_top data : 5
// a_top data : 3
// a_top data : 6
// a_top data : 8
// a_top data : 0


// a_top data : 0
// a_top data : 3
// a_top data : 5
// a_top data : 6
// a_top data : 8

// b_top data : 7
// b_top data : 9
// b_top data : 4
// b_top data : 1
// b_top data : 2

// */

//     deq_a.a_size = get_deq_a_size(&deq_a);
//     deq_b.b_size = get_deq_b_size(&deq_b);

//     deq_a.arr =(int *)malloc(sizeof(int) * deq_a.a_size);

//     int i = 0;
   
//     t_node *temp = deq_a.a_top;
    
//     while (temp)
//     {
//         deq_a.arr[i++] = temp->content;
//         temp = temp->next;
//     }

//     content_trans_idx(&deq_a);

// /*
// a_top data : 8
// a_top data : 9
// a_top data : 11
// a_top data : 0
// a_top data : 10
// a_top data : 1
// a_top data : 5
// a_top data : 3
// a_top data : 2
// a_top data : 7
// a_top data : 4
// a_top data : 6
// */

// /*b_top data : 10
// b_top data : 11
// b_top data : 9
// b_top data : 8
// b_top data : 0
// b_top data : 1
// b_top data : 5
// */
// /*
// a_top data : 3
// a_top data : 4
// a_top data : 5
// a_top data : 6
// a_top data : 10
// (lldb) p deq_print(deq_b)
// b_top data : 8
// b_top data : 11
// b_top data : 9
// b_top data : 7
// b_top data : 0
// b_top data : 1
// b_top data : 2
// */




//     sort(&deq_a, &deq_b);


//      if (!check_sort(&deq_a))
//          last_setting_deque(&deq_a);
    
//     deq_print(&deq_a);
//     deq_print(&deq_b);
//     return (0);
// }