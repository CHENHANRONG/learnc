public class MaxCurrencyQuestion {
    /**
     * 问题：给定一排n个硬币，其面值均为整数c1, c2, ..., cn, 这些整数并不一定两两不同。
     * 问如何选择硬币，使得在其原始位置互不相邻的条件下，所选硬币的总金额最大。
     *
     * 最大可选金额用F(n), 所有可行到选择划分为两组：
     * 1. 包含最后一枚硬币： 这时F(n) = Cn + F(n-2)
     * 2. 不包含最后一枚硬币（即最后第二枚）: 这时 F(n) = F(n-1)
     *
     * 递推方程为： F(n) = max{F(n), F(n-1)} = max{Cn+F(n-2), F(n-1)}, n>1
     * F(0) = 0, F(1) = c1;
     *
     *
     */

    public int coinRow(int c[]){
        int []F = new int[c.length+1];
        F[0] = 0;
        F[1] = c[0];
        for(int i=2;i<F.length;i++){
            F[i] = Math.max(c[i-1]+F[i-2], F[i-1]);
        }

        for(int j=0;j<F.length;j++){
            System.out.print(F[j]+"\t");
        }

        return F[F.length-1];
    }
}
