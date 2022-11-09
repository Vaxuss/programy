using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
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
using Label = System.Windows.Controls.Label;

namespace Tabliczka
{

    public partial class MainWindow : Window
    {
        bool upperClicked = false;
        bool lowerClicked = false;
        Button[,] przycisk = new Button[5, 5];
        Button UpperButton = new Button();
        Button LowerButton = new Button();
        Label[,] labels = new Label[6,6];
        
        public MainWindow()
        {
            InitializeComponent();
            Style style = this.FindResource("ButtonTemplate") as Style;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if(i == 0)
                    {
                        przycisk[i, j] = new Button
                        {
                            Content = j+1,
                            Style = style,
                        };
                        przycisk[i, j].Click += Button_Clicked_Upper;
                        Grid.SetColumn(przycisk[i, j], j+1);
                        Grid.SetRow(przycisk[i, j], i);
                        mainGrid.Children.Add(przycisk[i, j]);
                    }
                    if (j == 0)
                    {
                        przycisk[i, j] = new Button
                        {
                            Content = i + 1,
                            Style = style,
                        };
                        przycisk[i, j].Click += Button_Clicked_Lower;
                        Grid.SetColumn(przycisk[i, j], j);
                        Grid.SetRow(przycisk[i, j], i + 1);
                        mainGrid.Children.Add(przycisk[i, j]);
                    }
                }
            }

            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5; j++)
                {
                    labels[i, j] = new Label();
                    Grid.SetColumn(labels[i,j], i);
                    Grid.SetRow(labels[i,j], j);
                    mainGrid.Children.Add(labels[i,j]);
                }
            }
        }

        public void Button_Clicked_Upper(object sender, EventArgs e)
        {
            upperClicked = true;
            UpperButton = (Button)sender;
            if (upperClicked && lowerClicked)
            {
                All_Buttons_Clicked(UpperButton, LowerButton);        
            }

        }
        public void Button_Clicked_Lower(object sender, EventArgs e)
        {
            lowerClicked = true;
            LowerButton = (Button)sender;
            if (upperClicked && lowerClicked)
            {
                All_Buttons_Clicked(UpperButton, LowerButton);
            }
        }

        public void All_Buttons_Clicked(Button upper, Button lower)
        {
            Style labelStyle = this.FindResource("LabelTemplate") as Style;
            int X = Grid.GetColumn(upper);
            int Y = Grid.GetRow(lower);
            int length = 0;

            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5; j++)
                {
                    labels[i, j] = new Label
                    {
                        Style = labelStyle,
                    };
                    Grid.SetColumn(labels[i, j], i);
                    Grid.SetRow(labels[i, j], j);
                    mainGrid.Children.Add(labels[i, j]);
                }
            }
        }                    
    }
}
