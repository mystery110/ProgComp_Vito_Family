#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_INPUT_CHAR 6000
#define MAX_INFINITY 999999999
#define STREET_RANGE 30000
#define MAX_RELATIVE 500
int relative_street_number[MAX_RELATIVE];
int temp_int;

char *temp_char_pointer;

int main (){
	int test_case=0,test_case_index=0;
	char input[MAX_INPUT_CHAR];

	/*Read the number of test case
	 *  */
	if(fgets(input,sizeof(input),stdin)!=NULL){
		sscanf(input,"%d",&test_case);
	}

	for(test_case_index=0;test_case_index<test_case;test_case_index++){
		int final_ans_street=0;
		int shortest_distance=MAX_INFINITY;

		for(temp_int=0;temp_int<MAX_RELATIVE;temp_int++){
			relative_street_number[temp_int]=0;
		}


		/*For each test case, read the total number of relative first*/
		int number_of_relative=0,relative_index=0;
		/*Then start reading the street number relatives living in*/

			scanf("%d",&number_of_relative);

			for(relative_index=0;relative_index<number_of_relative;relative_index++){
				scanf("%d",&relative_street_number[relative_index]);

				/*delete the string up till white space ie meeted*/
			}

			/*remove the newline character*/
			fgetc(stdin);


			/*Start finding the shortest distance for all street*/
			int street_index=0;
			for(street_index=0;street_index<STREET_RANGE;street_index++){
				int distance=0;
				for(relative_index=0;relative_index<number_of_relative;relative_index++){
					distance=distance+abs(relative_street_number[relative_index]-street_index);

					if(distance>shortest_distance){
						break;
					}
				}
				if(distance<shortest_distance){
					shortest_distance=distance;
					final_ans_street=street_index;
				}
			}
			printf("%d\n",shortest_distance);
		}
}
