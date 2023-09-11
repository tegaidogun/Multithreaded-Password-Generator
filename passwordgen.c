#include "hash.h"
#include <pthread.h>
#include <time.h>

#define error(m, c) do{fprintf(stderr, "%s\n", m);exit(c);}while(0)
hashset h;
char* words[100000];
static int N;
typedef struct{
	int from_index;
	int to_index;
}producer_task;
static pthread_mutex_t mutex;

void* producer(void* args){
	producer_task* task = (producer_task*)args;
	for(int j = task->from_index; j <= task->to_index;j++){
		pthread_mutex_lock(&mutex);
		insert(&h, words[j]);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

static int m;
static int k;
static int l;
void* consumer(void* args){
	char password[25*l];
	for(int i = 0; i < k/m; i++){
		memset(password, 0, sizeof(password));
		for(int j = 0; j < l; j++){
			int random_index = rand() % N;
			char* random_word = words[random_index];
			pthread_mutex_lock(&mutex);
			int removal_success = delete_value(&h, random_word);
			pthread_mutex_unlock(&mutex);
			if(removal_success) {
				if(j) {
					strcat(password, ",");
					strcat(password, random_word);
				} else {
					strcpy(password, random_word);
				}
			} else {
				j--;
			}
		}
		printf("%s\n", password);
	}
	return NULL;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	int n;
	char* file;
	if(argc != 11)
		error("fatal error: use the following CLAs: -p n -c m -f -n k file -l l", 1);
	char* message = (char*) malloc(100);
	while(*++argv){
		if(argv[0][0] != '-'){
			sprintf(message, "fatal error: illegal command-line detected: %s", *argv);
			error(message, 2);
		}
		switch(argv[0][1]){
			case 'p':
			sscanf(*(++argv), "%d", &n);
			break;
			case 'c':
			sscanf(*(++argv), "%d", &m);
			break;
			case 'l':
			sscanf(*(++argv), "%d", &l);
			break;
			case 'n':
			sscanf(*(++argv), "%d", &k);
			break;
			case 'f':
			file = (char*) malloc(100);
			sscanf(*(++argv), "%s", file);
			break;
			default:
			sprintf(message, "fatal error: flag -%c is not supported", argv[0][1]);
			error(message, 3);
		}
	}
	if(k % m)
		error("fatal error: requested number of passwords is not divisible by the given number of consumers", 4);
	h = set_init();
	char word[500];
	FILE* f = fopen(file, "r");
	int i = 0;
	while(fgets(word, 500, f)){
		int n = strlen(word);
		if(!n)continue;
		if(word[n-1] == '\n')
			word[n-1] = '\0';
		words[i++] = strdup(word);
	}
	fclose(f);
	N = i;
	pthread_t producer_threads[n];
	producer_task tasks[n];
	for (int i = 0; i < n; i++) {
		tasks[i].from_index = i * N / n;
		tasks[i].to_index = (i + 1) * N / n - 1;
		pthread_create(&producer_threads[i], NULL, producer, &tasks[i]);
	}
	for (int i = 0; i < n; i++) {
		pthread_join(producer_threads[i], NULL);
	}
	pthread_t consumer_threads[m];
	for (int i = 0; i < m; i++) {
		pthread_create(&consumer_threads[i], NULL, consumer, NULL);
	}
	for (int i = 0; i < m; i++) {
		pthread_join(consumer_threads[i], NULL);
	}
	return 0;
}
