///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Project Name :  Packer Unpacker
//          Module       :  Unpacker_Package
//          Description  :  Only Accept input from user.import user define package.
//                          Main Login in User defined packagae MArvellous Unpacker class.
//          Author       :  Snehal Rohit Shitkal
//          Date         :  22/8/2025
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.io.*;

import MarvellousPackerUnpacker.MarvellousUnpacker;

///////////////////////////////////////////////////////////////////////////////////////////////////////
class Unpacker_Package
{
    public static void main(String A[])
    {
       try
       {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter the name of file that you want to Packing:");
            String PackName = sobj.nextLine();

            MarvellousUnpacker mobj = new MarvellousUnpacker(PackName);

            mobj.UnpackActivity();
       }
       catch(Exception eobj)
       {

       } 
    }// End of main
}// End of Unpacker_Package class


//////////////////////////////////////////////////////////////////////////////////////////////