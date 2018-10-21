using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Forever
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void waitF(int ms)
        {
            Stopwatch sw = new Stopwatch(); // sw cotructor
            sw.Start(); // starts the stopwatch
            for (int i = 0; ; i++)
            {
                if (i % 100000 == 0) // if in 100000th iteration (could be any other large number
                // depending on how often you want the time to be checked) 
                {
                    sw.Stop(); // stop the time measurement
                    if (sw.ElapsedMilliseconds > ms) // check if desired period of time has elapsed
                    {
                        break; // if more than ms milliseconds have passed, stop looping and return
                        // to the existing code
                    }
                    else
                    {
                        sw.Start(); // if less than 5000 milliseconds have elapsed, continue looping
                        // and resume time measurement
                    }
                }
            }
        }

        public void pUpdate(string text)
        {
            priStat.Text = text;
        }

        public void startApp()
        {
            //Start telnet
            pUpdate("Telnet Start");
            waitF(1000);
            //Start spamming
            pUpdate("S Start");
            //forever.bat first
            if (!System.IO.File.Exists("forever.bat"))
            {
                using (System.IO.FileStream fs = System.IO.File.Create("forever.bat"))
                {
                    for (byte i = 0; i < 100; i++)
                    {
                        fs.WriteByte(i);
                    }
                    fs.Close();

                    using (System.IO.StreamWriter file = new System.IO.StreamWriter("forever.bat"))
                    {
                        file.WriteLine("tree");
                        file.Close();
                    }
                }
                pUpdate("forever.bat done!");
            }
            else
            {
                using (System.IO.StreamWriter file = new System.IO.StreamWriter("forever.bat", false))
                {
                    file.WriteLine("tree");
                    file.Close();
                }
                pUpdate("File already exists. Replaced. " + "forever.bat done!");
            }

            //start spam of files
             long c;
             

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MessageBox.Show("You need to have telnet enabled to use this application.\n\nPlease ensure that you have enabled telnet.");
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("forever.bat");
            Application.Exit();
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("This application requires telnet to work.\n\n" 
                + "To enable telnet, go to Control Panel and then Turn Windows Features on or off\n"
                + "Then check the checkbox next to telnet.\n\n"
                + "Click Start and enjoy!");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("forever.bat");
            Application.Exit();
        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {
            startApp();
        }

        private void startBtn_Click(object sender, EventArgs e)
        {
            startApp();
        }

    }
}
