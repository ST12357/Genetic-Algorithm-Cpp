#include <bits/stdc++.h>
using namespace std;
int y=999999999;
int fit_func(int chrom[][6], int num)
{
    int flag=0;

    if(chrom[num][0]==1)
    {
        flag=1;
    }

    int sum=0;

    sum=sum+chrom[num][5]*2;
    sum=sum+chrom[num][4]*4;

    sum=sum+chrom[num][3]*8;
    sum=sum+chrom[num][2]*16;
    sum=sum+chrom[num][1]*32;
    y=sum;
    if(flag==1)
        sum=sum*-1;
    int fit=-(sum*sum)+5;
    return fit;



}


int main()
{

    int chrom[4][6],fit;

    for(int i=0; i<6; i++)
    {
        chrom[0][i]= rand()% 2;
    }

    for(int i=0; i<6; i++)
    {
        chrom[1][i]= rand()% 2;
    }

    for(int i=0; i<6; i++)
    {
        chrom[2][i]= rand()% 2;
    }

    for(int i=0; i<6; i++)
    {
        chrom[3][i]= rand()% 2;
    }

    int arr[4];



    for(int it=0; y!=0 ; it++)
    {
        for(int i=0; i<4; i++)

        {
            arr[i]=-fit_func(chrom,i);
            fit=fit_func(chrom,i);
        }


        int n,m;


        if(arr[0]>=arr[1])
        {
            if(arr[0]>=arr[2])
            {
                if(arr[0]>=arr[3])
                {
                    n=0;
                    arr[0]=0;
                }
                else
                {
                    n=3;
                    arr[3]=0;
                }
            }
            else if (arr[2]>=arr[3])
            {
                n=2;
                arr[2]=0;
            }
            else
            {
                n=3;
                arr[3]=0;
            }
        }
        else if(arr[1]>=arr[2])
        {
            if(arr[1]>=arr[3])
            {
                n=1;
                arr[1]=0;
            }
            else
            {
                n=3;
                arr[3]=0;
            }
        }


        if(arr[0]>=arr[1])
        {
            if(arr[0]>=arr[2])
            {
                if(arr[0]>=arr[3])
                {
                    m=0;
                    arr[0]=0;
                }
                else
                {
                    m=3;
                    arr[3]=0;
                }
            }
            else if (arr[2]>=arr[3])
            {
                m=2;
                arr[2]=0;
            }
            else
            {
                m=3;
                arr[3]=0;
            }
        }
        else if(arr[1]>=arr[2])
        {
            if(arr[1]>=arr[3])
            {
                m=1;
                arr[1]=0;
            }
            else
            {
                m=3;
                arr[3]=0;
            }
        }
        int k,l;
        if(m!=0 && n!=0)
            k=0;
        else if(m!=1 && n!=1)
            k=1;
        else if(m!=2 && n!=2)
            k=2;
        else
            k=3;

        if(m!=0 && n!=0 && k!=0)
            l=0;
        else if(m!=1 && n!=1 && k!=1)
            l=1;
        else if(m!=2 && n!=2 && k!=2)
            l=2;
        else
            l=3;

        int cross= rand()% 6;
        int p,q;
        p=cross;
        q=p-1;


        for(int i=p; i<6; i++)
        {
            chrom[n][i]=chrom[k][i];
            chrom[m][i]=chrom[l][i];
        }
        for(int i=q; i>=0; i--)
        {
            chrom[m][i]=chrom[k][i];
            chrom[n][i]=chrom[l][i];
        }


        int mut= rand()% 51;
        if(mut==20)
        {
            int mut_cn= rand()%6;
            int mut_chrom= rand()%4;
            chrom[mut_chrom][mut_cn]= 1-chrom[mut_chrom][mut_cn];
        }
    }

    cout<<"The value of x^2 = "<<fit<<endl;


    return 0;
}
