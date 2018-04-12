import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N, day, month, year;
        N = sc.nextInt();
        day = sc.nextInt();
        month = sc.nextInt();
        year = sc.nextInt();

        while(day != 0){

            Calendar c = new GregorianCalendar();
            c.set(GregorianCalendar.DAY_OF_MONTH, day);
            c.set(GregorianCalendar.MONTH, month-1);
            c.set(GregorianCalendar.YEAR, year);

            c.add(GregorianCalendar.DAY_OF_MONTH, N);

            System.out.println(c.get(GregorianCalendar.DAY_OF_MONTH)+" "
                    +(c.get(GregorianCalendar.MONTH)+1) +" "+c.get(GregorianCalendar.YEAR));


            N = sc.nextInt();
            day = sc.nextInt();
            month = sc.nextInt();
            year = sc.nextInt();
        }

    }
}
