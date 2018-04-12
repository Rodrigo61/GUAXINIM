
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;
public class Main {


    public static String sign(String monthday){

        int num = new Integer(monthday);

        if(num >= 121 && num <= 219){
            return "aquarius";
        }else if(num <= 120){
            return "capricorn";
        }else if(num <= 320){
            return "pisces";
        }else if(num <= 420){
            return "aries";
        }else if(num <= 521){
            return "taurus";
        }else if(num <= 621){
            return "gemini";
        }else if(num <= 722){
            return "cancer";
        }else if(num <= 821){
            return "leo";
        }else if(num <= 923){
            return "virgo";
        }else if(num <= 1023){
            return "libra";
        }else if(num <= 1122){
            return "scorpio";
        }else if(num <= 1222){
            return "sagittarius";
        }else{
            return "capricorn";
        }

    }

    public static void main(String[] args) throws Exception{

        Scanner sc = new Scanner(System.in);

        int n_cases;
        n_cases = sc.nextInt();
        int count_cases = 0;


        for (int w = 0; w < n_cases; ++w){

            String date_str = sc.next();

            int month = new Integer(date_str.substring(0,2));
            int day   = new Integer(date_str.substring(2,4));
            int year  = new Integer(date_str.substring(4));

            Calendar c = new GregorianCalendar();
            c.set(GregorianCalendar.DAY_OF_MONTH, day);
            c.set(GregorianCalendar.MONTH, month-1);
            c.set(GregorianCalendar.YEAR, year);

            c.add(GregorianCalendar.WEEK_OF_YEAR, 40);

            String month_str = c.get(GregorianCalendar.MONTH)+1+"";
            String day_str = c.get(GregorianCalendar.DAY_OF_MONTH)+"";
            
            if(month_str.length() == 1) month_str = "0"+month_str;
            if(day_str.length() == 1) day_str = "0"+day_str;

            System.out.println(++count_cases + " " + month_str + "/" + day_str + "/" + c.get(GregorianCalendar.YEAR) + " " + sign(month_str+day_str));

        }




    }
}
