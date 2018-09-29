public class ChangeMaking {
    /**
     *题目三：最少硬币找零问题
     * 给予不同面值的硬币若干种（每种硬币个数无限多），如何用若干种硬币组合为某种面额的钱，使硬币的的个数最少？
     *
     *
     * 在总金额为n-Dj的一堆硬币上加上一个面值为Dj的硬币，其中j = 1,...,m, 并且n>= Dj.
     *
     * F(n) = min{F(n-Dj)}+1
     * F(0) = 0
     *
     *
     *
     * 在现实生活中，我们往往使用的是贪心算法，比如找零时需要13元，我们先找10元，再找2元，再找1元。
     * 如果我们的零钱可用的有1、2、5、9、10。我们找零18元时，贪心算法的策略是：10+5+2+1，四种, 但是明明可以用两个9元的啊。
     *
     * 这种问题一般使用动态规划来解决。
     *
     */


    public int changeMake(int D[], int n){
        int F[] = new int[n+1];
        F[0] = 0;

        for(int i=1;i<=n;i++){
            int temp = Integer.MAX_VALUE;
            int j = 0;
            while(j<D.length && i>=D[j]){
                temp = Math.min(F[i-D[j]], temp);
                j++;
            }

            F[i] = temp+1;
        }


        return F[n+1];
    }


}
