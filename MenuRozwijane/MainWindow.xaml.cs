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

namespace MenuRozwijane
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            //ApplicationCommands.Close.InputGestures.Add(new KeyGesture(Key.Q, ModifierKeys.Control));
            ApplicationCommands.Copy.InputGestures.Clear();
            ApplicationCommands.Copy.InputGestures.Add(new KeyGesture(Key.J, ModifierKeys.Control));
            EditingCommands.IncreaseFontSize.InputGestures.Add(new KeyGesture(Key.F3, ModifierKeys.Shift | ModifierKeys.Control));
            InitializeComponent();
        }

        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void CommandBinding_CanExecute_1(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void CommandBinding_Executed_1(object sender, ExecutedRoutedEventArgs e)
        {
            HelpWindow helpWindow = new HelpWindow();
            helpWindow.ShowDialog();

        }
    }
}
