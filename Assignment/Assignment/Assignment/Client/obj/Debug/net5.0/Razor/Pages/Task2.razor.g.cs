#pragma checksum "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "2c85d2b3be6c206cafe8631b6c0efedd01de4203"
// <auto-generated/>
#pragma warning disable 1591
namespace Assignment.Client.Pages
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Components;
#nullable restore
#line 1 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using System.Net.Http;

#line default
#line hidden
#nullable disable
#nullable restore
#line 2 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using System.Net.Http.Json;

#line default
#line hidden
#nullable disable
#nullable restore
#line 3 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.AspNetCore.Components.Forms;

#line default
#line hidden
#nullable disable
#nullable restore
#line 4 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.AspNetCore.Components.Routing;

#line default
#line hidden
#nullable disable
#nullable restore
#line 5 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.AspNetCore.Components.Web;

#line default
#line hidden
#nullable disable
#nullable restore
#line 6 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.AspNetCore.Components.Web.Virtualization;

#line default
#line hidden
#nullable disable
#nullable restore
#line 7 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.AspNetCore.Components.WebAssembly.Http;

#line default
#line hidden
#nullable disable
#nullable restore
#line 8 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Microsoft.JSInterop;

#line default
#line hidden
#nullable disable
#nullable restore
#line 9 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Assignment.Client;

#line default
#line hidden
#nullable disable
#nullable restore
#line 10 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Assignment.Client.Shared;

#line default
#line hidden
#nullable disable
#nullable restore
#line 11 "D:\data structure\Blazorproj\Assignment\Assignment\Client\_Imports.razor"
using Assignment.Shared;

#line default
#line hidden
#nullable disable
    [Microsoft.AspNetCore.Components.RouteAttribute("/assignment2")]
    public partial class Task2 : Microsoft.AspNetCore.Components.ComponentBase
    {
        #pragma warning disable 1998
        protected override void BuildRenderTree(Microsoft.AspNetCore.Components.Rendering.RenderTreeBuilder __builder)
        {
            __builder.AddMarkupContent(0, "<h3>Task2</h3>\r\n");
            __builder.OpenElement(1, "div");
            __builder.AddAttribute(2, "class", "row");
            __builder.OpenElement(3, "div");
            __builder.AddAttribute(4, "class", "col-lg-3");
            __builder.OpenComponent<Microsoft.AspNetCore.Components.Forms.EditForm>(5);
            __builder.AddAttribute(6, "Model", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.Object>(
#nullable restore
#line 8 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                          sms

#line default
#line hidden
#nullable disable
            ));
            __builder.AddAttribute(7, "ChildContent", (Microsoft.AspNetCore.Components.RenderFragment<Microsoft.AspNetCore.Components.Forms.EditContext>)((context) => (__builder2) => {
                __builder2.OpenElement(8, "div");
                __builder2.AddMarkupContent(9, "<label>From sms :</label>\r\n                ");
                __builder2.OpenElement(10, "div");
                __builder2.OpenComponent<Microsoft.AspNetCore.Components.Forms.InputText>(11);
                __builder2.AddAttribute(12, "Value", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.String>(
#nullable restore
#line 12 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                             sms.FromNumber

#line default
#line hidden
#nullable disable
                ));
                __builder2.AddAttribute(13, "ValueChanged", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<Microsoft.AspNetCore.Components.EventCallback<System.String>>(Microsoft.AspNetCore.Components.EventCallback.Factory.Create<System.String>(this, Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.CreateInferredEventCallback(this, __value => sms.FromNumber = __value, sms.FromNumber))));
                __builder2.AddAttribute(14, "ValueExpression", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.Linq.Expressions.Expression<System.Func<System.String>>>(() => sms.FromNumber));
                __builder2.CloseComponent();
                __builder2.CloseElement();
                __builder2.CloseElement();
                __builder2.AddMarkupContent(15, "\r\n            ");
                __builder2.OpenElement(16, "div");
                __builder2.AddMarkupContent(17, "<label>To sms :</label>\r\n                ");
                __builder2.OpenElement(18, "div");
                __builder2.OpenComponent<Microsoft.AspNetCore.Components.Forms.InputText>(19);
                __builder2.AddAttribute(20, "Value", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.String>(
#nullable restore
#line 18 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                             sms.ToNumber

#line default
#line hidden
#nullable disable
                ));
                __builder2.AddAttribute(21, "ValueChanged", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<Microsoft.AspNetCore.Components.EventCallback<System.String>>(Microsoft.AspNetCore.Components.EventCallback.Factory.Create<System.String>(this, Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.CreateInferredEventCallback(this, __value => sms.ToNumber = __value, sms.ToNumber))));
                __builder2.AddAttribute(22, "ValueExpression", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.Linq.Expressions.Expression<System.Func<System.String>>>(() => sms.ToNumber));
                __builder2.CloseComponent();
                __builder2.CloseElement();
                __builder2.CloseElement();
                __builder2.AddMarkupContent(23, "\r\n            ");
                __builder2.OpenElement(24, "div");
                __builder2.AddMarkupContent(25, "<label>Sender Id :</label>\r\n                ");
                __builder2.OpenElement(26, "div");
                __builder2.OpenComponent<Microsoft.AspNetCore.Components.Forms.InputText>(27);
                __builder2.AddAttribute(28, "Value", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.String>(
#nullable restore
#line 24 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                             sms.SenderId

#line default
#line hidden
#nullable disable
                ));
                __builder2.AddAttribute(29, "ValueChanged", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<Microsoft.AspNetCore.Components.EventCallback<System.String>>(Microsoft.AspNetCore.Components.EventCallback.Factory.Create<System.String>(this, Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.CreateInferredEventCallback(this, __value => sms.SenderId = __value, sms.SenderId))));
                __builder2.AddAttribute(30, "ValueExpression", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.Linq.Expressions.Expression<System.Func<System.String>>>(() => sms.SenderId));
                __builder2.CloseComponent();
                __builder2.CloseElement();
                __builder2.CloseElement();
                __builder2.AddMarkupContent(31, "\r\n            ");
                __builder2.OpenElement(32, "div");
                __builder2.AddMarkupContent(33, "<label>Message :</label>\r\n                ");
                __builder2.OpenElement(34, "div");
                __builder2.OpenComponent<Microsoft.AspNetCore.Components.Forms.InputTextArea>(35);
                __builder2.AddAttribute(36, "Value", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.String>(
#nullable restore
#line 30 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                                 sms.Message

#line default
#line hidden
#nullable disable
                ));
                __builder2.AddAttribute(37, "ValueChanged", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<Microsoft.AspNetCore.Components.EventCallback<System.String>>(Microsoft.AspNetCore.Components.EventCallback.Factory.Create<System.String>(this, Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.CreateInferredEventCallback(this, __value => sms.Message = __value, sms.Message))));
                __builder2.AddAttribute(38, "ValueExpression", Microsoft.AspNetCore.Components.CompilerServices.RuntimeHelpers.TypeCheck<System.Linq.Expressions.Expression<System.Func<System.String>>>(() => sms.Message));
                __builder2.CloseComponent();
                __builder2.CloseElement();
                __builder2.CloseElement();
                __builder2.AddMarkupContent(39, "\r\n            ");
                __builder2.OpenElement(40, "div");
                __builder2.OpenElement(41, "button");
                __builder2.AddAttribute(42, "type", "submit");
                __builder2.AddAttribute(43, "class", "btn btn-success");
                __builder2.AddAttribute(44, "onclick", Microsoft.AspNetCore.Components.EventCallback.Factory.Create<Microsoft.AspNetCore.Components.Web.MouseEventArgs>(this, 
#nullable restore
#line 34 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                                                         sendsms

#line default
#line hidden
#nullable disable
                ));
                __builder2.AddMarkupContent(45, "\r\n                    Send SMS\r\n                ");
                __builder2.CloseElement();
                __builder2.CloseElement();
            }
            ));
            __builder.CloseComponent();
            __builder.CloseElement();
            __builder.AddMarkupContent(46, "\r\n    ");
            __builder.OpenElement(47, "div");
            __builder.AddAttribute(48, "class", "col-lg-9");
#nullable restore
#line 41 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
         if (smss == null)
        {

#line default
#line hidden
#nullable disable
            __builder.AddMarkupContent(49, "<p><em>Loading...</em></p>");
#nullable restore
#line 43 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                      }
        else
        {

#line default
#line hidden
#nullable disable
            __builder.OpenElement(50, "table");
            __builder.AddAttribute(51, "class", "table");
            __builder.AddMarkupContent(52, "<thead><tr><th>Id</th>\r\n                        <th>From</th>\r\n                        <th>To</th>\r\n                        <th>Date</th>\r\n                        <th>Status</th></tr></thead>\r\n                ");
            __builder.OpenElement(53, "tbody");
#nullable restore
#line 57 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                     foreach (var mail in smss)
                    {

#line default
#line hidden
#nullable disable
            __builder.OpenElement(54, "tr");
            __builder.OpenElement(55, "td");
            __builder.AddContent(56, 
#nullable restore
#line 60 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                             mail.ID

#line default
#line hidden
#nullable disable
            );
            __builder.CloseElement();
            __builder.AddMarkupContent(57, "\r\n                        ");
            __builder.OpenElement(58, "td");
            __builder.AddContent(59, 
#nullable restore
#line 61 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                             mail.FromNumber

#line default
#line hidden
#nullable disable
            );
            __builder.CloseElement();
            __builder.AddMarkupContent(60, "\r\n                        ");
            __builder.OpenElement(61, "td");
            __builder.AddContent(62, 
#nullable restore
#line 62 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                             mail.ToNumber

#line default
#line hidden
#nullable disable
            );
            __builder.CloseElement();
            __builder.AddMarkupContent(63, "\r\n                        ");
            __builder.OpenElement(64, "td");
            __builder.AddContent(65, 
#nullable restore
#line 63 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                             mail.Date.ToShortDateString()

#line default
#line hidden
#nullable disable
            );
            __builder.CloseElement();
            __builder.AddMarkupContent(66, "\r\n                        ");
            __builder.OpenElement(67, "td");
            __builder.AddAttribute(68, "style", 
#nullable restore
#line 64 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                     mail.Status == "failed"? $"background:Red;" : $"background:green;"

#line default
#line hidden
#nullable disable
            );
            __builder.AddContent(69, 
#nullable restore
#line 64 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                                                                                                           mail.Status

#line default
#line hidden
#nullable disable
            );
            __builder.CloseElement();
            __builder.CloseElement();
#nullable restore
#line 66 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
                    }

#line default
#line hidden
#nullable disable
            __builder.CloseElement();
            __builder.CloseElement();
#nullable restore
#line 69 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"

        }

#line default
#line hidden
#nullable disable
            __builder.CloseElement();
            __builder.CloseElement();
        }
        #pragma warning restore 1998
#nullable restore
#line 75 "D:\data structure\Blazorproj\Assignment\Assignment\Client\Pages\Task2.razor"
       

    public SMS sms { get; set; }
    private SMS[] smss;

    protected override async Task OnInitializedAsync()
    {
        sms = new SMS();
        sms.Date = DateTime.Now;
        sms.Status = "";
        smss = await Http.GetFromJsonAsync<SMS[]>("Services");
    }
    public void sendsms()
    {
        Http.PostAsJsonAsync<SMS>("Services", sms);
        StateHasChanged();
    }

#line default
#line hidden
#nullable disable
        [global::Microsoft.AspNetCore.Components.InjectAttribute] private HttpClient Http { get; set; }
    }
}
#pragma warning restore 1591
