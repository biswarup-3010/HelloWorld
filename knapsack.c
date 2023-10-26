#include<stdio.h>
struct item{
	double cost;
	double weight;
	double ratio;
};
void sort(struct item arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j].ratio < arr[j+1].ratio){
				struct item temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(){
	int n;
	printf("Enter no of items : ");
	scanf("%d",&n);
	struct item arr[20];
	printf("Enter the cost and weight of the items :\n");
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&arr[i].cost,&arr[i].weight);
		arr[i].ratio = arr[i].cost / arr[i].weight;
	}
	sort(arr,n);
	printf("Enter max volume :");
	int vol=0;
	scanf("%d",&vol);
	double final_val=0;
	for(int i=0;i<n;i++){
		if(arr[i].weight <= vol){
			vol -= arr[i].weight;
			final_val += arr[i].cost;			
		}
		else{
			final_val += (arr[i].ratio)*vol;
			break;
		}
	}
	printf("Maximum knapshack = %lf",final_val);
	return 0;
}
