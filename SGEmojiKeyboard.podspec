Pod::Spec.new do |s|
  s.name             = "SGEmojiKeyboard"
  s.version          = "0.2.1"
  s.summary          = "An emoji keyboard view that can replace the default iOS keyboard. This is a update of SGEmojiKeyboard."
  s.description      = <<-DESC
                       SGEmojiKeyboard is a replacement view for the default keyboard 
                       for iOS that contains all the emojis supported by iOS. This keyboard 
                       view intends to be cutomizable to the point that you can easily alter 
                       it according to your needs.
                       DESC
  s.homepage         = "https://github.com/ayushgoel/SGEmojiKeyboard"

  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { "Eric B" => "bthiep148@gmail.com" }
  s.source           = { :git => "https://github.com/ericbui148/SGEmojiKeyboard", :tag => "#{s.version}" }

  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.requires_arc = true
  s.source_files = 'SGEmojiKeyboard/*.{h,m}'
  s.resources = ['Resources/*.{plist}', 'SGEmojiKeyboard/Stickers/**/*.png']
  s.dependency "MultiSelectSegmentedControl"
end
