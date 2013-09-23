#define N 1000
#define M 15


typedef struct{
int card_num[M]; //对应的5张牌
int card_color[4]; //对应的颜色
int conti; //连续最大值值
int color; //同色
int TWOK[2]; //2张相同牌最大值
int TK; //3张相同牌的值
int FK; //4张相同牌的值
int Mk; //最大值手牌
}Poker;


void confirmPoker(Poker *g1, Poker *g2,char temp[]);//确认手牌
void iscolor(Poker *g1,Poker *g2); //确认是否是同色牌
void isconti(Poker *g1,Poker *g2); //确认是否是连续
void manyK(Poker *g1,Poker *g2); //确认相同手牌
bool judge_g1(Poker *g1,Poker *g2); //判断赢家
void clearPoker(Poker *g1,Poker *g2); //清除手牌所有属性


void confirmPoker(Poker *g1, Poker *g2,char temp[])
{
for (int i = 0,j = 1; i < M; i += 3,j += 3)
{
switch(temp[i])
{
case '2':g1->card_num[2]++;break;
case '3':g1->card_num[3]++;break;
case '4':g1->card_num[4]++;break;
case '5':g1->card_num[5]++;break;
case '6':g1->card_num[6]++;break;
case '7':g1->card_num[7]++;break;
case '8':g1->card_num[8]++;break;
case '9':g1->card_num[9]++;break;
case 'T':g1->card_num[10]++;break;
case 'J':g1->card_num[11]++;break;
case 'Q':g1->card_num[12]++;break;
case 'K':g1->card_num[13]++;break;
case 'A':g1->card_num[14]++;break;
}
switch(temp[j])
{
case 'H':g1->card_color[0]++;break;
case 'S':g1->card_color[1]++;break;
case 'D':g1->card_color[2]++;break;
case 'C':g1->card_color[3]++;break;
}
}
for (; i < M*2; i += 3,j += 3)
{
switch(temp[i])
{
case '2':g2->card_num[2]++;break;
case '3':g2->card_num[3]++;break;
case '4':g2->card_num[4]++;break;
case '5':g2->card_num[5]++;break;
case '6':g2->card_num[6]++;break;
case '7':g2->card_num[7]++;break;
case '8':g2->card_num[8]++;break;
case '9':g2->card_num[9]++;break;
case 'T':g2->card_num[10]++;break;
case 'J':g2->card_num[11]++;break;
case 'Q':g2->card_num[12]++;break;
case 'K':g2->card_num[13]++;break;
case 'A':g2->card_num[14]++;break;
}
switch(temp[j])
{
case 'H':g2->card_color[0]++;break;
case 'S':g2->card_color[1]++;break;
case 'D':g2->card_color[2]++;break;
case 'C':g2->card_color[3]++;break;
}
}
for (i = 0; i < M;i++)
{
if (g1->card_num[i] == 1 && g1->Mk < i)
{
g1->Mk = i;
}
if (g2->card_num[i] == 1 && g2->Mk < i)
{
g2->Mk = i;
}
}
iscolor(g1,g2);
isconti(g1,g2);
manyK(g1,g2);
}


void iscolor(Poker *g1,Poker *g2)
{
for (int i = 0; i < 4; i++)
{
if (g1->card_color[i] == 5)
{
g1->color = 1;
}
if (g2->card_color[i] == 5)
{
g2->color = 1;
}
}
}


void isconti(Poker *g1,Poker *g2)
{
for (int i = 0; i <= M-5;i++)
{
for (int j = i; j < i+5 && g1->card_num[i] != 0; j++)
{
if (g1->card_num[j] == 0)
{
break;
}
}
if (j-i == 5)
{
g1->conti = j-1;
}
for (j = i; j < i+5 && g2->card_num[i] != 0; j++)
{
if (g2->card_num[j] == 0)
{
break;
}
}
if (j-i == 5)
{
g2->conti = j-1;
}
}
}


void manyK(Poker *g1,Poker *g2)
{
for (int i = 0; i < M; i++)
{
switch(g1->card_num[i])
{
case 2:
if (g1->TWOK[0] == 0)
g1->TWOK[0] = i;
else
g1->TWOK[1] = i;
break;
case 3:g1->TK = i;break;
case 4:g1->FK = i;break;
default:break;
}
switch(g2->card_num[i])
{
case 2:
if (g2->TWOK[0] == 0)
g2->TWOK[0] = i;
else
g2->TWOK[1] = i;
break;
case 3:g2->TK = i;break;
case 4:g2->FK = i;break;
default:break;
}
}
int temp;
if (g1->TWOK[0] < g1->TWOK[1])
{
temp = g1->TWOK[0];
g1->TWOK[0] = g1->TWOK[1];
g1->TWOK[1] = temp;
}
if (g2->TWOK[0] < g2->TWOK[1])
{
temp = g2->TWOK[0];
g2->TWOK[0] = g2->TWOK[1];
g1->TWOK[1] = temp;
}
}


bool judge_g1(Poker *g1,Poker *g2)
{
if(g1->color == 1 && g2->color == 1){
if (g1->conti > g2->conti){
return true;
}if(g2->conti == 0 && g1->conti == 0 && g1->Mk > g2->Mk){
return true;
}
}if (g1->color ==1 && g2->color == 0){
if(g1->conti != g2->conti){
return true;
}if(g1->conti == 0 && g2->conti == 0){
if (g2->FK == 0 && g2->TWOK[0] == 0 || g2->TK == 0 ){
return true;
}
}
}if (g1->color == 0 && g2->color == 1){
if(g1->conti == 0 && g2->conti == 0){
if (g1->FK != 0 || g1->TWOK[0] != 0 && g1->TK != 0){
return true;
}
}
}
if(g2->color == 0 && g1->color == 0){
if (g1->conti > g2->conti){
if (g2->conti != 0){
return true;
}if (g2->conti == 0){
if (g2->FK == 0 && g2->TK == 0 || g2->TWOK[0] == 0){
return true;
}
}
}if(g1->conti < g2->conti){
if(g1->conti == 0){
if (g1->FK != 0 || g1->TK != 0 && g1->TWOK[0] != 0){
return true;
}
}
}if(g2->conti == 0 && g1->conti == 0){
if (g1->FK > g2->FK){
return true;
}if(g1->FK == g2->FK && g2->FK != 0 && g1->Mk > g2->Mk){
return true;
}if(g1->FK == 0 && g2->FK == 0){
if(g1->TK > g2->TK){
if (g2->TK != 0){
if(g1->TWOK[0] >= g2->TWOK[0]){
return true;
}
}if (g2->TK == 0){
return true;
}
}if(g1->TK < g2->TK){
if (g1->TK != 0 && g1->TWOK[0] != 0 && g2->TWOK[0] == 0){
return true;
}
}if(g2->TK == g1->TK){
if(g1->TK != 0){
if(g1->TWOK[0] > g2->TWOK[0]){
return true;
}if(g2->TWOK[0] == 0 && g1->TWOK[0] == 0 && g1->Mk >g2->Mk){
return true;
}
}if(g1->TK == 0){
if (g1->TWOK[0] > g2->TWOK[0]){
if (g2->TWOK[0] != 0){
if (g1->TWOK[1] >= g2->TWOK[1]){
return true;
}
}if (g2->TWOK[0] == 0){
return true;
}
}if (g2->TWOK[0] == g1->TWOK[0]){
if (g2->TWOK[0] != 0){
if (g1->TWOK[1] > g2->TWOK[1]){
return true;
}if(g2->TWOK[1] == g1->TWOK[1] && g1->Mk > g2->Mk){
return true;
}
}if (g1->TWOK[0] == 0 && g1->Mk > g2->Mk){
return true;
}
}if (g1->TWOK[0] < g2->TWOK[0]){
if (g1->TWOK[0] != 0 && g1->TWOK[1] != 0 && g2->TWOK[1] == 0){
return true;
}
}
}
}
}
}
}
return false;
}




void clearPoker(Poker *g1,Poker *g2)
{
memset(g1->card_num,0,sizeof(g1->card_num));
memset(g1->card_color,0,sizeof(g1->card_color));
g1->color = 0;
g1->conti = 0;
g1->FK = 0;
g1->TK = 0;
g1->TWOK[0] = 0;
g1->TWOK[1] = 0;
g1->Mk = 0;
memset(g2->card_num,0,sizeof(g2->card_num));
memset(g2->card_color,0,sizeof(g2->card_color));
g2->color = 0;
g2->conti = 0;
g2->FK = 0;
g2->TK = 0;
g2->TWOK[0] = 0;
g2->TWOK[1] = 0;
g2->Mk = 0;
}


int main()
{
	clock_t ts,te;
	ts=clock();
	int answer = 0;
	char temp[M*2]={0};
	Poker *g1,*g2;
	g1 = (Poker*)malloc(sizeof(Poker));
	g2 = (Poker*)malloc(sizeof(Poker));
	FILE *f;
	f = fopen("poker.txt","r");
	for (int i = 0; i < N; i++)
	{
		clearPoker(g1,g2);
		fread(temp,sizeof(temp),1,f);
		confirmPoker(g1,g2,temp);
		if (judge_g1(g1,g2) == true)
		{
			answer++;
		}
	}
	fclose(f);
	printf("\nanswer %d",answer);
	te=clock();
	printf("\ntime difference: %ds\n",(te-ts)/CLOCKS_PER_SEC);
	getchar();
	return 0;
}