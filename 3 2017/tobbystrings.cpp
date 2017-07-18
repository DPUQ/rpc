#include <bits/stdc++.h>
using namespace std;
#define MAXCHAR 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct node{
	int prefix_count;
	bool isEnd;
	struct node *child[MAXCHAR];
}* head;

void init(){
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;
	
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = CHAR_TO_INDEX(word[i]);
		if(current->child[letter] == NULL)
			current->child[letter] = new node();
		current->child[letter]->prefix_count++;
		current = current->child[letter];       
	}
	current->isEnd = true;	
}

static int res = 0;
static int n,q,l;

void buscar(node *current,int j,int i,char *a){
    if(l==i){
    	if(j==1){
    		res+= current->prefix_count;
    	}else{
    		res+= current -> prefix_count *l;
    	}
    	return;
    }
    if(j==1){
    	 if(current->child[CHAR_TO_INDEX(a[i])]){
    	 	buscar(current->child[CHAR_TO_INDEX(a[i])],j,i+1,a);
    	 }
    }
    else{
       for(int k=0; k < MAXCHAR; k++){
       	if(current->child[k]==NULL )continue;
        buscar(current->child[k],j+(CHAR_TO_INDEX(a[i])!= k),i+1,a);       	 
       }

    }
}

int main(){

	
	string a;

     static char s[131072];
	while(scanf("%d %d %d",&n,&q,&l)!=EOF){
		init();
        for(int i=0; i < n; i++){
         cin >> a;
           insert(a);
        }

        for(int i=0; i < q; i++){
        	res=0;
            scanf("%s", s);
        	buscar(head,0,0,s);
        	printf("%d\n",res); 
        }
	}

	return 0;
}

