using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using Xamarin.Forms;

namespace Stoper
{
    public partial class MainPage : ContentPage
    {
        ObservableCollection<SavedTime> lista = new ObservableCollection<SavedTime>();
        public MainPage()
        {
            InitializeComponent();
        }
        Timer timer;
        int mins = 0, secs = 0, milliseconds = 0;
        private void btn_Start_Clicked(object sender, EventArgs e)
        {
            timer = new Timer();
            timer.Interval = 1; // 1 milliseconds  
            timer.Elapsed += Timer_Elapsed; ;
            timer.Start();
        }

        private void btn_Reset_Clicked(object sender, EventArgs e)
        {
            mins = 0; secs = 0; milliseconds = 0;
            stoper.Text = string.Format("{0:00}:{1:00}.{2:00}", mins, secs, milliseconds / 10);
        }

        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            milliseconds++;
            if (milliseconds >= 1000)
            {
                secs++;
                milliseconds = 0;
            }
            if (secs == 59)
            {
                mins++;
                secs = 0;

            }
            Device.BeginInvokeOnMainThread(() =>
            {
                stoper.Text = string.Format("{0:00}:{1:00}.{2:00}", mins, secs, milliseconds / 10);
            });
        }

        private void btn_Between_Clicked(object sender, EventArgs e)
        {
            lista.Add(new SavedTime(stoper.Text));
        }

        private void btn_Stop_Clicked(object sender, EventArgs e)
        {
            timer.Stop();
            timer = null;
        }
    }
}
