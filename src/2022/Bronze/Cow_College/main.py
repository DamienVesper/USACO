from sys import stdin as fin

n = fin.readline();
cI = fin.readline();

cows = list(map(int, cI.split(" ")));

ans = 0;
c = 0;

cows.sort()
l = len(cows);

for i in range(l):
    b = cows[i];
    tempAns = b * (l - i);

    if (tempAns > ans):
        ans = tempAns;
        c = b;

print(ans, c);
