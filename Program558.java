import java.util.*;
import java.time.LocalDate;
import java.io.*;

//Done
class StudyLog
{
    public LocalDate Date;
    public String Subject;
    public double Duration;
    public String Description;
    

    public StudyLog(LocalDate A,String B,Double C,String D)
    {
        this.Date = A;
        this.Subject = B;
        this.Duration = C;
        this.Description = D;

    }
    @Override
    public String toString()
    {
        return Date+" | "+Subject+" | "+Duration+" | "+Description;
    }
    //getter method
    public LocalDate getDate()
    {
        return Date;
    }
    public String getSubject()
    {
        return Subject;
    }
    public double getDuration()
    {
        return Duration;
    }
    public String getDescription()
    {
        return Description;
    }
}

class StudyTracker
{
    //Datastucture to hold the data about study
    private ArrayList<StudyLog> Database = new ArrayList<StudyLog>();

    public void InsertLog()
    {
        Scanner scanerobj = new Scanner(System.in);

        System.out.println("----------------------------------------------------------------------");
        System.out.println("-------------Please Enter the Valid Details of your Study:------------");
        System.out.println("----------------------------------------------------------------------");
        
        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please provide the name of Subject like C/C++/JAVA/OS/DS");
        String sub = scanerobj.nextLine();

        System.out.println("Enter the Time period of your stude in hours:");
        double dur = scanerobj.nextDouble();
        
        scanerobj.nextLine();           //flushing

        System.out.println("Please provide the Description about the Study for Future Reference:");
        String Desc = scanerobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj,sub,dur,Desc);

        Database.add(studyobj);

        System.out.println("Study Log get Stored Successfully:");
        System.out.println("----------------------------------------------------------------------");
  
    }

    public void DisplayLog()
    {
        System.out.println("----------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as database is Empty:");
            System.out.println("----------------------------------------------------------------------");
            return;
        }

        System.out.println("----------------------------------------------------------------------");
        System.out.println("--------------Log Report from Marvellous Study Tracker:---------------");
        System.out.println("----------------------------------------------------------------------");

        for(StudyLog sobj:Database)
        {
            System.out.println(sobj);
        }
        System.out.println("----------------------------------------------------------------------");

    }

    public void ExportCSV()
    {

        System.out.println("----------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Export as database is Empty:");
            System.out.println("----------------------------------------------------------------------");
            return;
        }

        String FileName =  "MarvellousStudy.csv";
        
        //creayte new csv
        try(FileWriter fwobj = new FileWriter(FileName))
        {

            //Write CSV header
            fwobj.write("Date,Subject,Duration,Description\n");

            //travel Database
            for(StudyLog sobj:Database)
            {
                fwobj.write(sobj.getDate()+","+
                            sobj.getSubject().replace(","," ")+","+
                            sobj.getDuration()+","+
                            sobj.getDescription().replace(","," ")+"\n"
                            );
            
            }
            System.out.println("Log created Successfully");
       
        }
        catch(Exception eobj)
        {
            System.out.println("Exception occured while creating the CSV:");
            System.out.println("Report this issue to Marvellous Infossystem:");

        }

    }

    public void SummeryByDate()
    {

        System.out.println("----------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as database is Empty:");
            System.out.println("----------------------------------------------------------------------");
            return;
        }

        System.out.println("----------------------------------------------------------------------");
        System.out.println("--------------Summery by date from Marvellous Study Tracker:---------------");
        System.out.println("----------------------------------------------------------------------");

        TreeMap<LocalDate,Double> tobj = new TreeMap<LocalDate,Double>();

        LocalDate lobj = null;

        double d,old;
        for(StudyLog sobj:Database)
        {
           lobj = sobj.getDate();
           d = sobj.getDuration();

           if(tobj.containsKey(lobj))
           {
                old = tobj.get(lobj);
                tobj.put(lobj,d+old);
           }
           else
           {
                tobj.put(lobj,d);
           }
        }
        //Display Details as per subject:
            for(LocalDate ldobj : tobj.keySet())
        {
            System.out.println("Date:"+ldobj+" Total Study "+tobj.get(ldobj));
        }
        System.out.println("----------------------------------------------------------------------");
        
    }

    public void SummeryBySubject()
    {

        System.out.println("----------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as database is Empty:");
            System.out.println("----------------------------------------------------------------------");
            return;
        }

        System.out.println("----------------------------------------------------------------------");
        System.out.println("--------------Summery by Subject from Marvellous Study Tracker:---------------");
        System.out.println("----------------------------------------------------------------------");

        TreeMap<String,Double> tobj = new TreeMap<String,Double>();

        double d,old;
        String s;
        for(StudyLog sobj:Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();

           if(tobj.containsKey(s))
           {
                old = tobj.get(s);
                tobj.put(s,d+old);
           }
           else
           {
                tobj.put(s,d);
           }
        }
        //Display Details as per date:

        for(String str : tobj.keySet())
        {
            System.out.println("Subject :"+str+" Total Study "+tobj.get(str));
        }
        System.out.println("----------------------------------------------------------------------");
    


    }

}

class Program558       //StudyTrackerStarter
{
    public static void main(String A[])
    {
        StudyTracker stobj = new StudyTracker();

        Scanner scannerobj = new Scanner(System.in);
        int iChoice = 0;

        System.out.println("----------------------------------------------------------------------");
        System.out.println("-------------WelCome to Marvellous Study Tracker Application----------");
        System.out.println("----------------------------------------------------------------------");

        do{
            System.out.println("Please Select the Appropriate option:");
            System.out.println("1: Insert new study Log Database");
            System.out.println("2: View All Study Log:");
            System.out.println("3: Summery of Study Log Date :");
            System.out.println("4: Summery of Study Log Subject:");
            System.out.println("5: Export Study Log to CSV file:");
            System.out.println("6: Exit the application:");

            iChoice = scannerobj.nextInt();

            switch(iChoice)
            {
                case 1:     //Insert new study Log Database
                    stobj.InsertLog();
                    break;

                case 2:     //View All Study Log
                    stobj.DisplayLog();
                    break;
                    
                case 3:     //Summery of Study Log Date 
                    stobj.SummeryByDate();
                    break;
                case 4:     //Summery of Study Log Subject
                    stobj.SummeryBySubject();
                    break;
                case 5:     //Export Study Log to CSV file
                    stobj.ExportCSV();
                    break;
                case 6:     //Exit the application:
                    System.out.println("----------------------------------------------------------------------");
                    System.out.println("Thank you for using Marvellous Log Application:");
                    System.out.println("----------------------------------------------------------------------");
                    break;
                default:
                    System.out.println("Please enter the Valid Option:");

            }
        }while(iChoice != 6);

       
       

    }
}