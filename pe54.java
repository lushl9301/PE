/*
 *copy from nayuki
 *good practice for java?
 */

public final class pe054 implements ProjectEulerSolution {
    
    public static void main(String[] args) {
        System.out.println(new pe054().run());
    }
    
    public String run() {
        int count = 0;
        for (String hand : HANDS) {
            String[] cards = hand.split(" ");
            if (cards.length != 10)
                throw new AssertionError();
            Card[] player1 = new Card[5];
            Card[] player2 = new Card[5];
            for (int i = 0; i<5; i++) {
                player1[i] = new Card(cards[i]);
                player2[i] = new Card(cards[i+5]);
            }
                    
            if (getScore(player1) > getScore(player2))
                count++;
        }
        return Integer.toString(count);
    }
    
    private static final class Card {
        public final int rank;
        public final int suit;
        
        public Card(int rank, int suit) {
            if (rank <0 || rank>13 || suit<0 || suit>=4)
                throw new IllegalArgumentException();
            this.rank = rank;
            this.suit = suit;
        }
        
        public Card(String str) {
            this("23456789TJQKA".indexOf(str.charAt(0)), "HCSD".indexOf(str.charAt(1)));
        }
        
        public boolean equals(Object obj) {
            if (!(obj instanceof Card))
                return false;
            Card other = (Card) obj;
            return rank == other.rank && suit == other.suit;
        }
    }
    
    private static int getScore(Card[] hand) {
        if (hand.length != 5)
            throw new IllegalArgumentException();
        
        int[] rankCounts = new int[13];
        int flushSuit = hand[0].suit;
        for (Card card : hand) {
            rankCounts[card.rank]++;
            if (card.suit != flushSuit)
                flushSuit = -1;
        }
        
        int[] rankCountHist = new int[6];
        for (int i = 0; i < rankCounts.length; i++)
            rankCountHist[rankCounts[i]]++;
        
        int bestCards = get5FrequentHighestCards(rankCounts, rankCountHist);
        int straightHighRank = getStraightHighRank(rankCounts);
        
        if (straightHighRank != -1 && flushSuit != -1)
            return 8 << 20 | straightHighRank;
        if (rankCountHist[4] == 1)
            return 7 << 20 | bestCards;
        if (rankCountHist[3] == 1 && rankCountHist[2] == 1)
            return 6 << 20 | bestCards;
        if (flushSuit != -1)
            return 5 << 20 | bestCards;
        if (straightHighRank != -1)
            return 4 << 20 | bestCards;
        if (rankCountHist[3] == 1)
            return 3 << 20 | bestCards;
        if (rankCountHist[2] == 2)
            return 2 << 20 | bestCards;
        if (rankCountHist[2] == 1)
            return 1 << 20 | bestCards;
        return bestCards;        
    }
    
    private static int get5FrequentHighestCards(int[] ranks, int[] rankHist) {
        int result = 0;
        int count = 0;
        
        for (int i = rankHist.length - 1; i >= 0; i--) {
            for (int j = ranks.length -1; j >= 0; j--) {
                if (ranks[j] == i) {
                    for (int k = 0; k < i && count < 5; k++, count++)
                        result = result << 4 | j;
                }
            }
        }
        if (count != 5)
            throw new IllegalArgumentException();
        return result;
    }
    
    private static int getStraightHighRank(int[] ranks) {
  outer:
        for (int i = ranks.length - 1; i >= 3; i--) {
            for (int j = 0; j < 5; j++) {
                if (ranks[(i - j + 13) % 13] == 0)
                    continue outer;
            }
            return i;
        }
        return -1;
    }
        
    private static String[] HANDS = {
        // add data here... loading from poker.txt 
    };
}
