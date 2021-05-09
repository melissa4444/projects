import java.util.Scanner;
import java.util.Random;

class MyFavoriteApp
{

    public static void main(String[] args)

    {

        Scanner user = new Scanner(System.in);
        Random random = new Random();
        final int LIMIT = 9;
        final int TIMES = 3;

        int guess1;
        int guess2;
        int guess3;

        final int gen1 = random.nextInt(LIMIT);
        final int gen2 = random.nextInt(LIMIT);
        final int gen3 = random.nextInt(LIMIT);

        final int winZ = 0;
        final double winT = 10;
        final double winH = 100;
        final double winTh = 1000;
        final double winMil = 1000000;

        System.out.println("\t\t\tLets Play a Game!");
        System.out.println("\t\t\t You Vs Computer");
        System.out.println("Guess three numbers between 0-9 to earn MONEY!");


        System.out.println("\nEnter your 1st Guess: ");
        guess1 = user.nextInt();

        System.out.println("Enter your 2nd Guess: ");
        guess2 = user.nextInt();

        System.out.println("Enter your 3rd Guess: ");
        guess3 = user.nextInt();

        System.out.println("Random Numbers are: ");
        System.out.println(gen1 + " \t " + gen2 + " \t " + gen3);


        if (guess1 == gen1 && guess2 == gen2 && guess3 == gen3) {

            System.out.println("\n\tYou have Won: $" + winMil);

        }
        else
        {

            int count = 0;

            if (guess1 == gen1)
            {
                count++;
            }
            if (guess2 == gen2)
            {
                count++;
            }
            if (guess3 == gen3)
            {
                count++;
            }

            switch (count)
            {
                case 3:
                    System.out.println("\n!You have Won $$$" + winTh + " TIME TO PARTY!");
                    break;
                case 2:
                    System.out.println("\n!You have Won $" + winH + " ENOUGH FOR A LOT OF PIZZA!");
                    break;
                case 1:
                    System.out.println("\n!You have Won $" + winT + " ENOUGH FOR PIZZA!");
                    break;
                case 0:
                    System.out.println("\n!You Won NOTHING $" + winZ + " JUST STOP PLAYING!");
                    break;
            }

        }
        System.out.println("\nGamberlers Anonymous Southern California \nHotline Number: 855-2CALLGA (855-222-5542)");
    }

}

