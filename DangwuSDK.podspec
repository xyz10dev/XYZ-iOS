#
#  Be sure to run `pod spec lint XYZ.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "DangwuSDK"
  spec.version      = "1.0.0"
  spec.summary      = "XYZ SDK"

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  spec.description  = "ios sdk"

  spec.homepage     = "https://github.com/xyz10dev/XYZ-iOS"
  spec.license      = { :type => "MIT" }
  spec.author       = { "bai" => "osspinlock@gmail.com" }
  spec.source       = { :git => "https://github.com/xyz10dev/XYZ-iOS.git", :tag => "#{spec.version}" }
  spec.platform     = :ios, '8.0'

  spec.vendored_frameworks = 'DangwuSDK.framework'
  spec.requires_arc = true

  spec.pod_target_xcconfig = {
    'GCC_PREPROCESSOR_DEFINITIONS' =>
    'GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1 '
  }

  spec.frameworks  = "JavaScriptcore", "SystemConfiguration", "CoreTelephony", "CoreLocation", "Security", "CoreMotion", "Accelerate"

  spec.libraries = "z", "c++", "stdc++"

  spec.dependency 'AFNetworking'
  spec.dependency 'SocketRocket'
  spec.dependency 'Protobuf', '~>3.5'

end
