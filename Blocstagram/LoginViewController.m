//
//  LoginViewController.m
//  Blocstagram
//
//  Created by Fusion on 7/16/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import "LoginViewController.h"
#import "DataSource.h"

NSString *const LoginViewControllerDidAccessTokenNotification = @"LoginViewControllerDidGetAccessTokenNotification";


@interface LoginViewController ()<UIWebViewDelegate>

@property (nonatomic, weak) UIWebView *webView;
@property (nonatomic) BOOL hasAddedBackButton;

@end

@implementation LoginViewController


- (NSString *)redirectURI {
    return @"http://bloc.io";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.hasAddedBackButton = NO;
    
    UIWebView *webView = [[UIWebView alloc] init];
    webView.delegate = self;
    
    [self.view addSubview:webView];
    self.webView = webView;
    
    self.title = NSLocalizedString(@"Login", @"Login");
    
    NSString *urlString = [NSString stringWithFormat:@"https://instagram.com/oauth/authorize/?client_id=%@&redirect_uri=%@&response_type=token", [DataSource instagramClientID], [self redirectURI]];
    
    NSURL *url = [NSURL URLWithString:urlString];
    
    if (url) {
        NSURLRequest *request = [NSURLRequest requestWithURL:url];
        [self.webView loadRequest:request];
    }
}

- (void)dealloc {
    // Removing this line can cause a flickering effect when you relaunch the app after logging in, as the web view is briefly displayed, automatically authenticates with cookies, returns the access token, and dismisses the login view, sometimes in less than a second.
    [self clearInstagramCookies];
    
    // see https://developer.apple.com/library/ios/documentation/uikit/reference/UIWebViewDelegate_Protocol/Reference/Reference.html#//apple_ref/doc/uid/TP40006951-CH3-DontLinkElementID_1
    self.webView.delegate = nil;
}


#pragma mark - Clear Instagram Cookies
/**
 Clears Instagram cookies. This prevents caching the credentials in the cookie jar.
 */
- (void) clearInstagramCookies {
    for(NSHTTPCookie *cookie in [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies]) {
        NSRange domainRange = [cookie.domain rangeOfString:@"instagram.com"];
        if(domainRange.location != NSNotFound) {
            [[NSHTTPCookieStorage sharedHTTPCookieStorage] deleteCookie:cookie];
        }
    }
}

- (void) viewWillLayoutSubviews {
    self.webView.frame = self.view.bounds;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (BOOL) webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    NSLog(@"%s - %@", __PRETTY_FUNCTION__, [request description]);
    NSString *urlString = request.URL.absoluteString;
    if ([urlString hasPrefix:[self redirectURI]]) {
        //This contains our auth token
        NSRange rangeOfAccessTokenParameter = [urlString rangeOfString:@"access_token="];
        NSUInteger indexOfTokenStarting = rangeOfAccessTokenParameter.location + rangeOfAccessTokenParameter.length;
        NSString *accessToken = [urlString substringFromIndex:indexOfTokenStarting];
        [[NSNotificationCenter defaultCenter] postNotificationName:LoginViewControllerDidAccessTokenNotification object:accessToken];
        
        return NO;
    }
    
    return YES;
}


- (void)webViewDidStartLoad:(UIWebView *)webView {
    if ([webView canGoBack] && !self.hasAddedBackButton ) {
        UIBarButtonItem *btn = [[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain target:self action:@selector(goingBack:)];
//        self.navigationItem.leftBarButtonItem = btn;
        [self.navigationItem setLeftBarButtonItem:btn animated:YES];
        self.hasAddedBackButton = YES;
        
    } else if (![webView canGoBack] && self.hasAddedBackButton) {
        [self.navigationItem setLeftBarButtonItem:nil animated:YES];
        self.hasAddedBackButton = NO;
    }

}

#pragma mark - Actions
- (void) goingBack:(id) sender {
    [self.webView goBack];
}

@end
