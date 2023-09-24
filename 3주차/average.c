#include <stdio.h>

typedef struct {
	int math;
	int korean;
	int english;
} Score;
	
double math_average(Score s1, Score s2, Score s3)
{
	double aver;
	aver = (double)(s1.math + s2.math + s3.math) / 3;
	return aver;
}

void high_score(Score s1, int* max)
{
	*max = s1.korean;
	if (s1.math > s1.korean)
		*max = s1.math;
	else
		*max = s1.korean;
	if (s1.english > *max)
		*max = s1.english;
}

void main()
{
	Score a = {90, 80, 46}, b = {55, 67, 83}, c = {80, 39, 100};
	int score;
	double math_aver;

	printf("The average score of math is %lf\n", math_average(a, b, c));
	high_score(a, &score);
	printf("The student a's highest score is %d\n", score);
}
