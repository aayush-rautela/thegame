#include<stdio.h>
int main()
{
    int c,d,e,p1=1,p2=2,sizeb,peng,i,i1,filled_tiles,boards,tilehalf,j,x,y;
    char name1[15],name2[15];
    printf("Enter 1 for Single-player mode\n");
    printf("Enter 2 for Multi-player mode ");
    scanf("%d",&c);
    if(c==2)
    {
        printf("Enter name of Player 1");
        fgets(name1,sizeof(name1),stdin);       //somehow this line is broken
        printf("Enter name of Player 2\n");
        fgets(name2,sizeof(name2),stdin);       //but this one works
        printf("Enter size of board(5-25)");    //board is square
        scanf("%d",&sizeb);
        struct tile     //1 for no of fish,2 whose penguine is there,3 might be needed??
        {
            int fish;
            int playerid;
            int lets_see;
        } tile[sizeb][sizeb];
        printf("Enter number of Penguines(Should be less than 1/4 of total available space)");  //if you wanna get known numer of peng
        scanf("%d",&peng);
        for(i=0; i<sizeb; i++)
        {
            for(i1=0; i1<sizeb; i1++)

            {
                tile[i][i1].fish=rand(4);  //assigning 0-3 fish  //fix this
                tile[i][i1].playerid=0;  //no player
                if(tile[i][i1].fish!=0)
                {
                    filled_tiles++;
                }
            }
        }

        boards=(sizeb*sizeb)/4;
        tilehalf=filled_tiles/2;
        if(peng<=boards&&peng<tilehalf) //only allowed to place on tile with penguine
        {
            for(j=0; j<peng; j++)
            {

l1:
                puts(name1);
                printf(":Enter coordinates to place peng in x(enter)y format");
                scanf("%d%d",&x,&y);
                if(tile[x][y].fish!=0&&tile[x][y].playerid==0)
                {
                    p1=p1+tile[x][y].fish;
                    tile[x][y].playerid=1;
                }
                else
                {
                    goto l1;
                }
l2:
                puts(name2);
                printf(":Enter coordinates to place peng in x y format");
                scanf("%d%d",&x,&y);
                if(tile[x][y].fish!=0&&tile[x][y].playerid==0)
                {
                    p2=p2+tile[x][y].fish;
                    tile[x][y].playerid=2;
                }
                else
                {
                    goto l2;
                }


            }
        }
    }
}
