package hackerrank.introduction;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.time.LocalDate;
import java.util.Arrays;
import java.util.Calendar;
import java.util.List;

public class DateAndTime {

    /* Java8 way */
    /*public static String findDay(int month, int day, int year) {
        LocalDate date = LocalDate.of(year, month, day);
        return date.getDayOfWeek().toString();
    }*/

    /* Java7 way - ugly */
    public static String findDay(int month, int day, int year) {
        List<String> days = Arrays.asList("SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY");
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month - 1, day); // month-1 because the January starts from index 0
        int p = calendar.get(Calendar.DAY_OF_WEEK) - 1; // why -1 ??
        return days.get(p);
    }


    public static void main(String[] args) {
        ClassLoader loader = Thread.currentThread().getContextClassLoader();
        InputStream stream = loader.getResourceAsStream("date.txt");
        assert stream != null;

        InputStreamReader streamReader = new InputStreamReader(stream, StandardCharsets.UTF_8);
        String[] lines = new String[2];
        try (BufferedReader reader = new BufferedReader(streamReader)) {
            String line;
            while((line = reader.readLine()) != null) {
                lines = line.split("\\s+");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        int month = Integer.parseInt(lines[0]);
        int day = Integer.parseInt(lines[1]);
        int year = Integer.parseInt(lines[2]);

        System.out.println(findDay(month, day, year));
    }
}
