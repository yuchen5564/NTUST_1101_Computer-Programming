#pragma once
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// print data in array with length n
/// </summary>
/// <param name="seq">input array</param>
/// <param name="n">length of array</param>
void print_data(int* seq, int n)
{
	int* i;
	for (i = &seq[0]; i < &seq[n]; i++) {
		if (i == &seq[n - 1]) {
			printf("%d", *i);
		}
		else {
			printf("%d ", *i);
		}
		
	}
}

/// <summary>
/// insert seq2 into seq1 at position p
/// </summary>
/// <param name="seq1">data in seq1</param>
/// <param name="n1">length of seq1</param>
/// <param name="seq2">data in seq2</param>
/// <param name="n2">length of seq2</param>
/// <param name="seq_out">buffer to store insertion result</param>
/// <param name="n_total">total sequence length after insertion</param>
/// <param name="p">insert position in seq1</param>
void insert_sequence(int* seq1, int n1, int* seq2, int n2, int* seq_out, int* n_total, int p)
{
	int* i, * j;
	*n_total = n1 + n2;

	for (i = &seq_out[0]; i < &seq_out[*n_total]; i++) {
		if (i == &seq_out[p]) {
			for (j = &seq_out[p]; j < &seq_out[p + n2]; j++) {
				*j = *seq2;
				seq2++;
			}
			i += n2;
		}
		*i = *seq1;
		seq1++;
	}
}
