#ifndef FT_LIST_H
# define FT_LIST_H
# define BUF 4096

typedef struct s_list
{
    char **strs;
    char *stroka;
	char ob;
    char fr;
    char sq;
    int l;
    int dl;
    int strok;
    int dlina;
    int shst;
    int dlst;
}	t_list;

#endif
