using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace absoluteLayout
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
            //BoxView grayBox = new BoxView { Color = Color.Gray};
            //AbsoluteLayout.SetLayoutBounds(grayBox, new Rectangle(0, 0, 1, 1));
            //AbsoluteLayout.SetLayoutFlags(grayBox, AbsoluteLayoutFlags.All);
            //BoxView maroonBox = new BoxView { Color = Color.Maroon };
            //AbsoluteLayout.SetLayoutBounds(maroonBox, new Rectangle(0.5, 0.5, 100, 100));
            //AbsoluteLayout.SetLayoutFlags(maroonBox, AbsoluteLayoutFlags.PositionProportional);
            //Button btn = new Button { Text = "TWO FLAGS" };
            //AbsoluteLayout.SetLayoutBounds(btn, new Rectangle(0, 1, 1, 55));
            //AbsoluteLayout.SetLayoutFlags(btn, AbsoluteLayoutFlags.PositionProportional | AbsoluteLayoutFlags.WidthProportional);
            //Content = new AbsoluteLayout
            //{
            //    Children = { grayBox, maroonBox, btn }
            //};
        }
    }
}
