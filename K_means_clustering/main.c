/***********************************
K means clustering sample
 TAN ZI QI  2018/12/27
************************************/

#include <stdio.h>
#include <stdlib.h>

int k = 2;
int N = 8;  // number of samples

// structure of samples
struct vector{
    double x;
    double y;
    double z;
    int cluster_type;
};

// function: calculate the Manhattan_distance between two samples
double Manhattan_distance(struct vector vector1, struct vector vector2) {
    double distance = 0.0;
    distance = fabs(vector1.x - vector2.x) + fabs(vector1.y - vector2.y) + fabs(vector1.z - vector2.z);
    return distance;
}

// Update_clustering_center
void Update_clustering_center(struct vector sample[], struct vector clustering_center[]) {
    int j = 1;
    double term1x = 0.0;
    double term1y = 0.0;
    double term1z = 0.0;
    double term2x = 0.0;
    double term2y = 0.0;
    double term2z = 0.0;
    double num1 = 0;
    double num2 = 0;
    for( j = 1; j <= N; j++ ){
        if( sample[j].cluster_type == 1 ){
            term1x = term1x + sample[j].x;
            term1y = term1y + sample[j].y;
            term1z = term1z + sample[j].z;
            num1++;
        }
        else{
            term2x = term2x + sample[j].x;
            term2y = term2y + sample[j].y;
            term2z = term2z + sample[j].z;
            num2++;
        }
    }

    term1x = term1x / num1;
    term1y = term1y / num1;
    term1z = term1z / num1;

    term2x = term2x / num2;
    term2y = term2y / num2;
    term2z = term2z / num2;

    clustering_center[1].x = term1x;
    clustering_center[1].y = term1y;
    clustering_center[1].z = term1z;

    clustering_center[2].x = term2x;
    clustering_center[2].y = term2y;
    clustering_center[2].z = term2z;

}

int main()
{
    int times = 3;
    struct vector sample[N+1];
    struct vector clustering_center[k+1];
    clustering_center[1].x = 1.2;
    clustering_center[1].y = 2.6;
    clustering_center[1].z = 3.4;

    clustering_center[2].x = 2.8;
    clustering_center[2].y = 3.9;
    clustering_center[2].z = 4.0;

    sample[1].x = 1.2;
    sample[1].y = 2.6;
    sample[1].z = 3.4;

    sample[2].x = 2.8;
    sample[2].y = 3.9;
    sample[2].z = 4.0;

    sample[3].x = 3.2;
    sample[3].y = 4.0;
    sample[3].z = 5.0;

    sample[4].x = 3;
    sample[4].y = 3;
    sample[4].z = 1;

    sample[5].x = 1;
    sample[5].y = 1;
    sample[5].z = 2;

    sample[6].x = -1;
    sample[6].y = 0;
    sample[6].z = 0;

    sample[7].x = -2;
    sample[7].y = -1;
    sample[7].z = 0;

    sample[8].x = 2;
    sample[8].y = 0;
    sample[8].z = 1;

    int i = 0;
    int j = 1;
    while( i++ <= times ){
        printf("Times: %d clustering\n", i);
        printf("center1: (%lf,%lf,%lf)\n", clustering_center[1].x, clustering_center[1].y, clustering_center[1].z );
        printf("center2: (%lf,%lf,%lf)\n", clustering_center[2].x, clustering_center[2].y, clustering_center[2].z );

        for( j = 1; j <= N; j++ ) {
            printf("sample %d to center1  %lf\n", j, Manhattan_distance(clustering_center[1],sample[j]));
            printf("sample %d to center2  %lf\n", j, Manhattan_distance(clustering_center[2],sample[j]));

            if( Manhattan_distance(clustering_center[1],sample[j]) <= Manhattan_distance(clustering_center[2],sample[j]) ){
                sample[j].cluster_type = 1;
            }
            else{
                sample[j].cluster_type = 2;
            }
            printf("sample %d belongs to cluster %d", j, sample[j].cluster_type );
            printf("\n");

        }
        for( j = 1; j <= N; j++ ) {
            printf("%d ",sample[j].cluster_type);
        }
        printf("\n\n");

        // Update clustering center
        Update_clustering_center(sample, clustering_center);

    } // while-end


    for( j = 1; j <= N; j++ ) {
        printf("%d ",sample[j].cluster_type);
    }

    return 0;
}
