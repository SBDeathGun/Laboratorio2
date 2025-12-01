import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Comparator;
/*Città del Sud America (28/11/25)
Scrivere un programma Java che legge le città dal file 02struct/sudAmerica.txt e 
le stampa ordinate per nazione e all'interno di ogni nazione ordinate per nome della città.
 Inoltre si deve stampare per ogni nazione la somma delle popolazioni delle città di quella nazione. */
class Citta{
    public String nome;
    public int popolazione;
    public String nazione;
    Citta(String[] campi){
        assert (campi.length == 3);
        this.nome=(campi[0]).trim();
        this.popolazione=Integer.parseInt((campi[1]).trim());
        this.nazione=(campi[2]).trim();
    }
    @Override
    public String toString(){
        return this.nome +" " +this.popolazione+" "+ this.nazione;
    }
    



}

public class LeggiCitta {
    public static void main(String[] args) {
        ArrayList<Citta> citta= new ArrayList<Citta>();
        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            String letto=in.readLine();
            while(letto != null){
                citta.add(new Citta((letto.split(";"))));
                letto = in.readLine();
            }
            for(Citta c : citta){
                System.out.println(c);
            }
            System.out.print("\n\n\n");
            in.close();
        } catch (Exception e) {
            System.out.println(e);
            return;
        }
        citta.sort(new Comparator<Citta>() {

                @Override
                public int compare(Citta arg0, Citta arg1) {
                    if(arg0.nazione.compareTo(arg1.nazione)==0){
                        return arg0.popolazione-arg1.popolazione;
                    }
                    return arg0.nazione.compareTo(arg1.nazione); 
                }
                
            }
        );
        for(Citta c : citta){
            System.out.println(c);
        }

    }
    
    
}
