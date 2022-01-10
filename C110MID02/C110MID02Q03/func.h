#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Apply Caesar cipher to the message.
/// </summary>
/// <param name="msg">The message string for encryption.</param>
/// <param name="shift">The shift amount.</param>
void caesar_cipher(char* msg, int shift)
{
	int len = strlen(msg);
	shift = shift % 26;
	//printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		
		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			msg[i] += shift;
			if (msg[i] > 'Z') { //�W�L�ե�
				msg[i] -= 26;
			}
			if (msg[i] < 'A') { //�W�L�ե�
				msg[i] += 26;
			}
		}
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			msg[i] += shift;
			if (msg[i] > 'z') { //�W�L�ե�
				msg[i] -= 26;
			}
			if (msg[i] < 'a') { //�W�L�ե�
				msg[i] += 26;
			}
		}
	}


}

/// <summary>
/// Print the result.
/// </summary>
/// <param name="msg">A message string.</param>
void print_result(char* msg)
{
	int len = strlen(msg);
	for (int i = 0; i < len; i++) {
		printf("%c", msg[i]);
	}
	printf("\n");
}

