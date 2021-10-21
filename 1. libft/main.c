#include "libft.h"

//void	*ft_delelem(void *content)
//{
//	char *s = "123";
//
//	content = s;
//	return (content);
//}

int main(void)
{
/* atoi
	char num[] = "   -2147483648";
	char num1[] = "   -9223372036854775809";
	printf("%d\n", ft_atoi(num1));
	printf("%d\n", atoi(num1));
* strdup
	char num[] = "";
	printf(">%s<\n", ft_strdup(num));
	printf(">%s<\n", strdup(num));
* strrchr
	char *src = "âÄâ«ÅËËËÂ¯ËÂ¸Â¯.ÅÂ«ââââÂªâ¢Â¡Â¶Â¢ËË";
	char *d1 = strrchr(src, L'â');
	char *d2 = ft_strrchr(src, L'â');
	printf("src: >%s<\n", src);
	printf("strrchr: >%s<\n", d1);
	printf("ft_strrchr: >%s<\n", d2);
* bzero
	char *b = (char *) malloc(10);
	printf(">%s<\n",b);
	ft_bzero(b, 10);
	printf(">%s<\n",b);
	ft_bzero(b, 10);
	printf("%s\n",b);
* memcpy
	ft_memcpy(((void *)0), ((void *)0), 3);
* memchr
	char *src1 = "/|\x12\xff\x09\x42\2002\42|\\";
	char *src2 = "/|\x12\xff\x09\x42\2002\42|\\";
	int size = 10;

	printf("%s\n", (char *)ft_memchr(src1, '5', size));
	printf("%s\n", (char *)memchr(src2, '\200', size));
* //strncmp
	char *s1 = "abcdef";
	char *s2 = "";
	size_t size = 0;

	printf("%d\n", ft_strncmp(s1, s2, size));
	printf("%d\n", strncmp(s1, s2, size));
*
	char *src = "1234567890";
	char dst1[18];
	char dst2[18];

	//printf("%zu\n", sizeof(dst1));
	printf("%zu\n", ft_strlcpy(dst1, src, 10));
	printf("%zu\n", strlcpy(dst2, src, 10));
	printf("%s\n", dst1);
	printf("%s\n\n", dst2);

	char *str = "BBBB";
	char buff1[0xF00];
	char buff2[0xF00];

	printf("%zu\n", ft_strlcpy(buff1, str, 10));
	printf("%zu\n", strlcpy(buff2, str, 10));
	printf("%s\n", buff1);
	printf("%s\n", buff2);
*
*	char *str = "";
	char buff1[15];
	char buff2[15];
	size_t max = 15;

	buff1[0] = '\0';
	buff2[0] = '\0';
	buff1[11] = 'a';
	buff2[11] = 'a';
	printf("max         : %zu\n", max);
//	printf("strlen      : %zu\n", ft_strlen("there is no stars in the skythe cake is a lie "));
	printf("ft_strlcat  : Len_sum - %zu  >  ::%s::\n", ft_strlcat(buff1, str, max), buff1);
	printf("strlcat     : Len_sum - %zu  >  ::%s::\n", strlcat(buff2, str, max), buff2);
*
	dest_len = 15;
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		check_strlcat(dest, "lorem", 15, dest_len);
	}
	else if (arg == 2)
		check_strlcat(dest, "", 15, dest_len);
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		check_strlcat(dest, "lorem ipsum", 15, dest_len);
*/

/* ::::::::::::::::::::::::::::::::> Part 2 <:::::::::::::::::::::::::::::::: */
/* :::::::::::::::::::::::::::::::::> itoa <::::::::::::::::::::::::::::::::: */
/*	int num = 1234;

	printf ("Num     : >%d<\n", num);
	//printf ("Len of num: >%d<\n", ft_intlen(num));
	printf ("String  : >%s<\n", ft_itoa(num));
*/

/* ::::::::::::::::::::::::::::::::> substr <:::::::::::::::::::::::::::::::: */
/*char s1[] = "lorem ipsum dolor sit amet";
//	char *s2;
	size_t i = 0;

	printf("Len of string  :  >%zu<\n", ft_strlen(s1));

	//s2 = ft_substr(s1, 10, i);
	printf("Substring      :  >%s<\n", ft_substr(s1, 0, i));
*/

/* ::::::::::::::::::::::::::::::::> strtrim <::::::::::::::::::::::::::::::: */
/*	char s1[] = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
//	char s2[] = "\t \n";
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char s2[] = "\t \n";
	char *s3;

	s3 = ft_strtrim(s1, s2);

	printf("String to be trimmed  :  >>>%s<<<\n"
		   "With                  :  >>>%s<<<\n"
		   "Res                   :  >>>%s<<<\n", s1, s2, s3);
*/

/* ::::::::::::::::::::::::::::::::> strjoin <::::::::::::::::::::::::::::::: */
/*	char s1[] = "01234";
	char s2[] = "56789";
	char *s3;
	size_t i;

	s3 = ft_strjoin(s1, s2);

	printf("Substring: >%s<\n", s3);
*/

/* :::::::::::::::::::::::::::::::::> split <:::::::::::::::::::::::::::::::: */
	char s1[] = " Omfg, I did it perfectly, no tears, no tears ! ";
	char c = ' ';
	char **array;
	size_t i = 0;

	array = ft_split(s1, c);
	while (array[i])
	{
		printf("Split: >%s<\n", array[i++]);
	//	printf("String 2: >%s<\n", array[1]);
	//	printf("String 3: >%s<\n", array[2]);
	//	printf("String 4: >%s<\n", array[3]);
	//  i++;
	}
while (1);

/* ::::::::::::::::::::::::::::::> putnbr_fd <::::::::::::::::::::::::::::::: */
/*	int fd;

	fd = open("1test_file_for_putnbr.txt", O_WRONLY); *| O_APPEND | O_CREAT | O_EXCL
	if (fd > -1)
	{
		ft_putnbr_fd(-2147483648, fd);
		//write(fd, "123", 3);
	}
	close(fd);
*/

/* :::::::::::::::::::::::::::::::> striteri <::::::::::::::::::::::::::::::: */
/*
 *
 */

/* ::::::::::::::::::::::::::::::> Bonus part <:::::::::::::::::::::::::::::: */
/* ::::::::::::::::::::::::::::::::> lstsize <::::::::::::::::::::::::::::::: */
/*	t_list elem3;
	t_list elem2;
	t_list elem1;
	t_list elem4;

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = NULL;

	printf("lstsize  :  %d", ft_lstsize(&elem1));
*/

/* ::::::::::::::::::::::::::::::::> lstlast <::::::::::::::::::::::::::::::: */
/*	t_list elem3;
	t_list elem2;
	t_list elem1;
	t_list elem4;
	t_list *res;


	elem1.next = &elem2;
	elem2.next = &elem3;
	elem2.content = 10;
	elem3.next = &elem4;
	elem4.next = NULL;
	elem4.content = 5;
	res = ft_lstlast(&elem1);
	printf("lstlast  :  %d", res->content);
*/

/* ::::::::::::::::::::::::::::::> lstadd_back <::::::::::::::::::::::::::::: */
/*	t_list elem1;
	t_list elem2;
	t_list elem3;
	t_list elem4;
	t_list elem5 = {6, NULL};
	t_list *ptr;

	ptr = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = NULL;
	elem4.content = 6;
	printf("lstsize before  :  >%d\n",ft_lstsize(&elem1));
	ft_lstadd_back(&ptr, &elem5);
	printf("lstsize after   :  >%d\n",ft_lstsize(&elem1));
	//printf("lstlast  :  %d", (int)*res->content));
*/

/* :::::::::::::::::::::::::::::::> lstdelone <:::::::::::::::::::::::::::::: */
/*
 * void ft_del(void *)
{

}

	t_list elem4 = ft_lstnew((void *)'4');
	t_list elem3 = {(void *)'3', &elem4};
	t_list elem2 = {(void *)'2', &elem3};
	t_list elem1 = {(void *)'1', &elem2};
	t_list *ptr;
	t_list *res;

	ptr = &elem1;

	printf("lstsize before  :  %d", ft_lstsize(&elem1));

	(char *)res = (char *)ft_lstlast(&elem1);
	printf("lstlast before  :  %s", (char *)res->content);

	ft_lstdelone(elem4, void (*del)(void *));
	printf("lstsize after   :  %d", ft_lstsize(&elem1));

	res = ft_lstlast(&elem1);
	printf("lstlast after   :  %s", (char *)res->content);
*/
/* CHECKER WASN'T FINISHED */



/* :::::::::::::::::::::::::::::::::> lstmap <::::::::::::::::::::::::::::::: */
/*
	t_list *l = ft_lstnew(strdup(" 1 2 3 "));
	//t_list *ret;

	l->next = ft_lstnew(strdup("ss"));
	l->next->next = ft_lstnew(strdup("-_-"));
	ft_lstmap(l, NULL, ((void *)0));

	//printf("%s\n", (char *)ret->content);
	//printf("%s\n", (char *)ret->next->content);
	//printf("%s\n", (char *)ret->next->next->content);
*/
	return (0);
}