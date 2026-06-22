import java.util.ArrayList;  //1. Array only is not valid class in JAVA

public class Medic {
 
 public static void main(String[] args) {
  Hospital hosp = new Hospital();
  hosp.setHospitalName("HSA");     
        
  Doctors doc1 = new Doctors(1980,12,1);
  doc1.setDoctorName("Dr.Abu Ali");  
  Doctors doc2 = new Doctors(1981,1,1);
  doc2.setDoctorName("Dr.Kim Lee");     
  Doctors doc3 = new Doctors(1985,12,12);
  doc3.setDoctorName("Dr.Nadela A/P Ram");      
        
  ArrayList<Doctors> doctorList = new ArrayList<>();    //2. Doctors is <> is missing
  doctorList.add(doc1);  //2. use lowercase method name
  doctorList.add(doc2);  //3. use lowercase method name
  doctorList.add(doc3);  //4. use lowercase method name
        
        
  hosp.setDoctors(doctorList); //5. pass the list to hospital
        
  System.out.println("Size of list: " + doctorList.size()); //6. size is method, not field
  System.out.println(hosp.getDoctors()+ " are Doctors of "+  hosp.getHospName()); //7-8. getDoctors() and getHospName() is not defined in main
         
     
 doctorList.remove(1); //9. removes in incorrect 
 System.out.println("After remove:"); 
 System.out.println("Display list:" + doctorList );  

          
 Doctors newDoc1= new Doctors(1984,5,8);
 newDoc1.setDoctorName("Dr.Badariah");  
 doctorList.add(0,newDoc1); //7 

 Doctors newDoc2= new Doctors(1982,22,5);
 newDoc2.setDoctorName("Dr.Zang Yu"); 
 doctorList.add(3,newDoc2);  //8   

 System.out.println("After add two doctors:"); 
 System.out.println("Display list: "+ doctorList);   
     
 System.out.println("Doctor list and their birthday: ");
 System.out.println("First doctor: " + doctorList.get(0).getDoctorName() + "  " + doctorList.get(0).getBday());  //10 
 System.out.println("Second doctor: " + doctorList.get(1).getDoctorName() + "  " + doctorList.get(1).getBday());  //11   
 System.out.println("Third doctor : " + doctorList.get(2).getDoctorName() + "  " + doctorList.get(2).getBday());  //12   
 System.out.println("Forth doctor : "+ doctorList.get(3).getDoctorName() + "  " + doctorList.get(3).getBday());    //13   
 
 }
 
} //Medic

class Hospital {
     private String hospitalName;
     ArrayList<Doctors> doctors;  //14  
 
    public String getHospName() {
        return hospitalName;
    }
     public void setHospitalName(String hospName) {
        hospitalName = hospName;
    }
    public ArrayList<Doctors> getDoctors() {   
        return doctors;
    }
    public void setDoctors(ArrayList<Doctors> doc) {    
        doctors = doc;
    }
 
} //Hospital
 

class Doctors {
    private String doctorName;
    private Birthday bday;  //15. datatype is not written

    Doctors(int y,int m,int d){
        bday=new Birthday(y, m, d);
    }

    public String getDoctorName() {
        return doctorName;
    }
 
    public void setDoctorName(String docName) {
        doctorName = docName;
    }
   
    public String toString() {
        return doctorName;
    }

   public Birthday getBday() {
    return bday;}   
} //Doctors


class Birthday{
        int year,month,day;

        Birthday(int y,int m,int d){
            year=y;
            month=m;
            day=d;
        }

        public String toString(){
           return String.format("%s-%s-%s", year,month,day);
        }
    }//Birthday







