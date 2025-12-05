import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Elenco{
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            Set<String> set =new HashSet<String>();
            String line;
            ArrayList<String> arr = new ArrayList<String>();
            while((line = in.readLine()) !=null){
                set.add(line);
            }
            for(String str:set){
                arr.add(str);
            }
            arr.sort((String str1,String str2)->{
                if(str1.length() == str2.length()) return str1.compareTo(str2);
                return str1.length()-str2.length();
            });
            for(String str:arr){
                System.out.println(str);
            }
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    
    }
}