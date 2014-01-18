//SPOJ submission 5851191 (C++ 4.0.0-8) plaintext list. Status: WA, problem BST1, contest SPOJ. By ashk92 (ash), 2011-10-17 07:54:19.

    #include<iostream>
    using namespace std;
    #include<stdio.h>
//    #include<conio.h>
    struct node
    {
    int data;
    struct node * left;
    struct node * right;
    };
     
    struct node* insert(int n,struct node *p)
    {
    if(p==NULL)
    {
    p=new struct node();
    p->data=n;
    p->left=NULL;
    p->right=NULL;
    }
    else if(n>p->data)
      p->right=insert(n,p->right);
     else
      if(n<p->data)
        p->left=insert(n,p->left);
    return p;
    }
     
    void preorder(node *p)
    {
    if(p==NULL)
      return;
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
    }
     
    void postorder(node *p)
    {
    if(p==NULL)
    return ;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
    }
     
    int main()
    {
    int n,temp,i=0,j=0;
    char a[10];
    struct node *pt=NULL;
    cin>>n;
    int b;
    for(i=0;i<n;i++)
    {
      cin>>b;
      pt=insert(b,pt);
    }
//    for(i=0;i<n;i++)
//    pt=insert(b[i],pt);
//    fflush(stdin);
//    while((i=getchar())!='\n')
//    a[j++]=i;
//    a[j]='\0';
    cin>>a;
    if(a[0]=='p' && a[1]=='r' && a[2]=='e')
    {
      preorder(pt);
    }
    else
      postorder(pt);
//    delete pt;
//    delete []b;
//    getch();
    return 0;
    }
