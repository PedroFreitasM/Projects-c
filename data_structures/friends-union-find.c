#include <stdio.h>
#include <stdlib.h>

typedef struct object{
    int friendship;
    int size;
}citizen;

int find(citizen* town, int citizen);
void setUnion(citizen* town, int friend1, int friend2);

int main(){
    int tests, citizens, pairs;
    int max = 0;
    int friend1, friend2;
    scanf(" %d", &tests);
    int* results = (int*)malloc(tests * sizeof(int));
    for(int i = 0; i<tests; i++){
        scanf(" %d %d", &citizens, &pairs);
        citizen* town = (citizen*)malloc(citizens * sizeof(citizen));
        for(int j = 0; j < citizens; j++){
            town[j].friendship = (j);
            town[j].size = 1;
        }
        for(int j = 0; j < pairs; j++){
            scanf(" %d %d", &friend1, &friend2);
            setUnion(town, (friend1-1), (friend2-1));
        }
        max = 0;
        for(int j = 0; j < citizens; j++){
            int root = find(town, j);
            if(town[root].size > max) max = town[root].size;
        }
        results[i] = max;
        free(town);
    }
    for(int i = 0; i < tests; i++){
        printf("%d\n", results[i]);
    }
    free(results);

    return 0;
}

int find(citizen* town, int citizen){
    if(town[citizen].friendship != citizen){
        town[citizen].friendship = find(town, town[citizen].friendship);
    }
    return town[citizen].friendship;
}

void setUnion(citizen* town, int friend1, int friend2){
    int rootFriend1 = find(town, friend1);
    int rootFriend2 = find(town, friend2);

    if(rootFriend1 != rootFriend2){
        if(town[rootFriend1].size > town[rootFriend2].size){
            town[rootFriend2].friendship = rootFriend1;
            town[rootFriend1].size += town[rootFriend2].size;
        }else{
            town[rootFriend1].friendship = rootFriend2;
            town[rootFriend2].size += town[rootFriend1].size;
        }
    }
}
