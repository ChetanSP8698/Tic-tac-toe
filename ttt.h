typedef struct matrix {
	int a[3][3];
}matrix;

void init(matrix *t);
int insert(matrix *t, int val, int pos);
int check(matrix *t);
void printttt(matrix *t);
