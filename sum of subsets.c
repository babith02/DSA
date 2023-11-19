#include <stdio.h>
#include <stdlib.h>

static int total_nodes;
int i;
void printSubset(int A[], int size)
{
	for(i = 0; i < size; i++)
	{
		printf("%*d", 5, A[i]);
	}

	printf("\n");
}

int comparator(const void *pLhs, const void *pRhs)
{
	int *lhs = (int *)pLhs;
	int *rhs = (int *)pRhs;

	return *lhs > *rhs;
}

void subset_sum(int s[], int t[],
				int s_size, int t_size,
				int sum, int ite,
				int const target_sum)
{
	total_nodes++;

	if( target_sum == sum )
	{

		printSubset(t, t_size);

		if( ite + 1 < s_size && sum - s[ite] + s[ite+1] <= target_sum )
		{

			subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
		}
		return;
	}
	else
	{
		if( ite < s_size && sum + s[ite] <= target_sum )
		{

			for( i = ite; i < s_size; i++ )
			{
				t[t_size] = s[i];

				if( sum + s[i] <= target_sum )
				{
					subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
				}
			}
		}
	}
}
void generateSubsets(int s[], int size, int target_sum)
{
	int *tuplet_vector = (int *)malloc(size * sizeof(int));

	int total = 0;

	// sort the set
	qsort(s, size, sizeof(int), &comparator);

	for( i = 0; i < size; i++ )
	{
		total += s[i];
	}

	if( s[0] <= target_sum && total >= target_sum )
	{

		subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);

	}

	free(tuplet_vector);
}

int main()
{

	int n,target;
	printf("SUM OF SUBSET  BACKTRACKING PROGRAM\n");
	int weights[100];
	printf("\nEnter the number of elements in the set:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        scanf("%d",&weights[i]);
    }
    printf("\nEnter the target value of the subset:");
    scanf("%d",&target);

	generateSubsets(weights, n, target);

	printf("Total numbers of nodes generated %d\n", total_nodes);

	return 0;
}

