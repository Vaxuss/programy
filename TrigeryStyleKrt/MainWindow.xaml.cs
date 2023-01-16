using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TrigeryStyleKrt
{
    public partial class MainWindow : Window
    {
        Random rand = new Random();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Style style1 = this.FindResource("label1") as Style;
            Style style2 = this.FindResource("label2") as Style;
            Style style3 = this.FindResource("label3") as Style;
            string txt = txtBox.Text;
            string[] slowa = txt.Split();
            
            for(int i = 0; i < slowa.Length; i++)
            {
                int temp = rand.Next(0, 3);
                Label label = new Label();
                label.Content = slowa[i];
                switch (temp) 
                {
                    case 0:
                        label.Style = style1;
                        break;
                    case 1:
                        label.Style = style2;
                        break;
                    case 2:
                        label.Style = style3;
                        break;
                }

                panel.Children.Add(label);
                
            }
        }
    }
}
