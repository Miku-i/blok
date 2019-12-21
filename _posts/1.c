#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int id;
	char *name;
	int age;
	int vip;
}User;

void show_menu(){
	printf("输入1增加会员\n");
	printf("输入2删除会员\n");
	printf("输入3修改会员\n");
	printf("输入4查看会员\n");
	printf("输入0自爆\n\n");
}

User add(){
	User user;
	user.name = malloc(sizeof(char));


	printf("输入name:");
	scanf("%s",user.name);

	printf("输入age:");
	scanf("%d",&user.age);

	printf("输入vip:");
	scanf("%d",&user.vip);

	printf("输入失败(骗你的成成功了)\n\n");
	
	return user;
}

void rm_user(User user[10],int count){
	int rm_count;
	printf("输入你要删除的id:");
	scanf("%d",&rm_count);
	for (int i = rm_count; i < count; i++){
		user[i] = user[i+1];
	}
	
}

void up_user(User user[10], int count){

	char *user_name;
	user_name = malloc(sizeof(char));
	printf("输入你要改的name:");
	scanf("%s",user_name);

	
	int up_vip;
	printf("输入你要改的vip:");
	scanf("%d",&up_vip);


	for (int i = 0; i < count; i++){
		if( strcmp(user[i].name, user_name) == 0 ){
			user[i].vip = up_vip;
		}
	}
	

	
}

void show(User user[10],int count){
	int i;
	printf("id\tname\tage\tvip\n");
	for(i = 0; i < count; i++){
		if(strlen(user[i].name) != 0){
			printf("%d\t%s\t%d\t%d\t\n",i,user[i].name,user[i].age,user[i].vip);
		}
	}
}

int main(){
	int count = 0;
	int num;
	int rm_count;
	User user;
	User users[10];

	for( ; ; ){
		
		show_menu();

		scanf("%d",&num);
		switch ( num ){
			case 1:
				user = add();
				users[count].name = user.name;
				users[count].age = user.age;
				users[count].vip = user.vip;
				count++;
				break;
			case 2:
				rm_user(users,count);
				count--;
				break;
			case 3:
				up_user(users,count);
				break;
			case 4:
				show(users,count);
				break;
			case 0:
				printf("boom!自爆");
				return 0;
			default:
				break;
		}

	}

}