object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Game Xonix'
  ClientHeight = 429
  ClientWidth = 696
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnPaint = FormPaint
  DesignSize = (
    696
    429)
  PixelsPerInch = 96
  TextHeight = 13
  object shapePlayer: TShape
    Left = 272
    Top = 0
    Width = 18
    Height = 18
    Brush.Color = 10032962
    Shape = stCircle
  end
  object imageGameOver: TImage
    Left = 96
    Top = 72
    Width = 513
    Height = 249
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000001F40000
      00C808060000001E1913E8000008244944415478DAEDDDEF7512CD1FC661ECC0
      0E6207D2815A8994102B30A92094801DD881A683D88125D8010FFBFBF302D93D
      0FC3CE32939BEB3A276F6224DF990CFB497208BC590100AFDE9BD6030000F309
      3A00041074000820E8001040D0012080A003400041078000820E0001041D0002
      083A00041074000820E8001040D0012080A003400041078000820E0001041D00
      02083A00041074000820E8001040D0012080A003400041078000820E0001041D
      0002083A00041074000820E8001040D0012080A003400041078000820E000104
      1D0002083A00041074000820E8001040D0012080A003400041078000820E0001
      041D0002083A00041074000820E8001040D0012080A003400041078000820E00
      01041D0002083A00041074000820E8001040D0012080A003400041078000820E
      0001041D0002083A00041074000820E8001040D0012080A00340004107800082
      0E0001041D0002083A00041074000820E80BFAF9F3E7FE9A9F6FB7DB0D6FBEA6
      7463BBDDEED7EB75EB31562F2F2FABFBFB7BF70DA239E00BDA1F5CF3F33D3E3E
      AE1E1E1E7C4DE9C6F04DED870F1F5A8FB17A7E7E5E7DFCF8D17D83680EF88204
      9D5B27E8703D0EF882049D5B27E8703D0EF882049D5B27E8703D0EF882049D5B
      27E8703D0E78055317AD4F9F3E0DFF567D8F0F17A6FD8F1F3FCEFEF8A5E680FF
      EBE54CF63207B4E0205720E8DCBA5ECE642F73400B0E720582CEADEBE54CF632
      07B4E0205720E8DCBA5ECE642F73400B0E720582CEADEBE54CF63207B4E02017
      182E1687B793F76F369BD5DDDDDDC9FB97BA58ACD7EBFD76BB3DFBE3EFEFEF87
      A7BEF4B56631BD84B49739A00507B9C0C3C3C3FEEBD7AF677FBC8B05B7A29790
      F63207B4E02017107418D74B487B99035A70900B083A8CEB25A4BDCC012D38C8
      05041DC6F512D25EE680161CE402820EE37A09692F73400B0E7201418771BD84
      B49739A00507B980A0C3B85E42DACB1CD082835C40D0615C2F21ED650E68C141
      2E20E830AE9790F63207B4E02017107418D74B487B99035A70900B083A8CEB25
      A4BDCC012D38C8056A04BDF48253432F733C3E3E0E7B38EBCC4DBD104E8D39F6
      07D75C4BE979AAB1C6A5F412D21A7394DE46C95E2FF943418DFB468D39A6D6B8
      E475E8CDC1220B7F656C4201419F47D08F09BAA0D7DC2741C7261410F47904FD
      98A00B7ACD7D12746C4201419F47D08F09BAA0D7DC2741C7261410F47904FD98
      A00B7ACD7D12746C42811A77C6F57ABDDF6EB7B3E678FBF6EDEAFDFBF7CDE798
      F2EEDDBBD5DDDDDDC9FBBF7DFBB6DAED7627EF1FBB501C6E633FDCCEDF8699C7
      D6FEEBD7AFD59F3F7FCEDAA7A93986DB9E7B1B5317BDE1C2F5F7FB369BCDEAF3
      E7CF67ADA5D4CBCBCBEAFBF7EF67CF3797A05F37E863E7A9E4BE516A384BC399
      FADBD86C536BFCF2E5CBC96D1CAE43ABA7A7A759B30D04FDBF6C42815EFE6CAD
      978BE794D27D1ABB33B6F86D48CFB7516AEAA7B5A52E7CBD9CC95B087A8BBD9E
      FAED558DFBAE18D763230B08FA7904BDFD0558D02F9F43D04F09FAEB60230B08
      FA7904BDFD0558D02F9F43D04F09FAEB60230B08FA7904BDFD0558D02F9F43D0
      4F09FAEB60230B08FA7904BDFD0558D02F9F43D04F09FAEB60230BDC42D0379B
      CD7E78F4F51C538F729F22E8C76A3C2A79F8FF638F4A5EEA4FD904BDDFA0D738
      4FBF7FFFFECFDBC87A04BD2336B2C02D047DC9BF8D9E22E8F5F93BF4CBE7480B
      7A0D4B5E4304BD1E1B5940D09721E8F509FAE57308FA7973D45AA3A0D763230B
      08FA3204BD3E41BF7C0E413F6F8E5A6B14F47A6C6401415F86A0D727E897CF21
      E8E7CD516B8D825E8F8D2C20E8CB10F4FA04FDF23904FDBC396AAD51D0EBB191
      054A9F5FBC17251785E111B1F7F7F7B33EDFD473944F11F46363CF795DEA7F8F
      4A16F40BE72879EEFD1A4A5E1BA0C5792AF95A097A3B36B282255FE5A88692C8
      3C3F3F0FFF76D5571113F47FBF8DDEF5B2C6D7FADBAB929FF27BD9EB2982DE8E
      8DAC40D08F09BAA0B75AA3A0CF5B630D82DE8E8DAC40D08F09BAA0B75AA3A0CF
      5B630D82DE8E8DAC40D08F09BAA0B75AA3A0CF5B630D82DE8E8DAC2029E8C383
      E2D6EBF5AC73B1DBEDF61E1477F96DD47810D394A52EECBDACF17076574F4F4F
      677FFC2D04FDDAE749D0DBB1910B9A7A4183A5D4F853A51A17ADA99FF24B5E30
      2429E8537AF913C125F5F2CD6E8DDF3CD558632F73D4E2C559FA62231724E8C7
      047DDE1A6B10F4B66BEC658E5A04BD2F367241827E4CD0E7ADB106416FBBC65E
      E6A845D0FB62231724E8C7047DDE1A6B10F4B66BEC658E5A04BD2F367241827E
      4CD0E7ADB106416FBBC65EE6A845D0FB622317341CEC6B7EBEC31D7AF6A39887
      801DDE66CD313CEDE86EB73B9963B3D98C3E75EED83721A5730C4F9BF9F7539D
      0E4FD53B3C5D67EBDB985263AF4B5DF3F9DD07535FF36B9B3A93D75E632F73D4
      52E3BE7BED3399CC4602400041078000820E0001041D0002083A000410740008
      20E8001040D0012080A003400041078000820E0001041D0002083A0004107400
      0820E8001040D0012080A003400041078000820E0001041D0002083A00041074
      000820E8001040D0012080A003400041078000820E0001041D0002083A000410
      74000820E8001040D0012080A003400041078000820E0001041D0002083A0004
      1074000820E8001040D0012080A003400041078000820E0001041D0002083A00
      041074000820E8001040D0012080A003400041078000820E0001041D0002083A
      00041074000820E8001040D0012080A003400041078000820E0001041D000208
      3A00041074000820E8001040D0012080A003400041078000820E0001041D0002
      083A00041074000820E8001040D0012080A003400041078000820E0001041D00
      02083A00041074000820E8001040D00120C03FF14D5E6E1FBA8AD50000000049
      454E44AE426082}
    Visible = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 395
    Width = 696
    Height = 33
    Anchors = [akLeft, akRight, akBottom]
    Color = clInactiveCaption
    ParentBackground = False
    TabOrder = 0
    DesignSize = (
      696
      33)
    object labelLevel: TLabel
      Left = 32
      Top = 6
      Width = 61
      Height = 19
      Anchors = [akLeft, akBottom]
      Caption = 'Level: 1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Cooper Black'
      Font.Style = []
      ParentFont = False
    end
    object labelProgress: TLabel
      Left = 216
      Top = 6
      Width = 104
      Height = 19
      Anchors = [akLeft, akBottom]
      Caption = 'Progress: 0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Cooper Black'
      Font.Style = []
      ParentFont = False
    end
    object labelScore: TLabel
      Left = 440
      Top = 6
      Width = 64
      Height = 19
      Anchors = [akTop]
      Caption = 'Score: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 1710781
      Font.Height = -16
      Font.Name = 'Cooper Black'
      Font.Style = []
      ParentFont = False
    end
    object ShareVkImage: TImage
      Left = 603
      Top = 5
      Width = 25
      Height = 25
      Cursor = crHandPoint
      Anchors = [akRight, akBottom]
    end
    object ShareFacebookImage: TImage
      Left = 665
      Top = 5
      Width = 25
      Height = 25
      Cursor = crHandPoint
      Anchors = [akRight, akBottom]
    end
    object ShareTwitterImage: TImage
      Left = 634
      Top = 5
      Width = 25
      Height = 25
      Cursor = crHandPoint
      Anchors = [akRight, akBottom]
    end
  end
  object timerMovement: TTimer
    Interval = 17
    OnTimer = timerMovementTimer
  end
  object timerEnemy: TTimer
    Interval = 25
    OnTimer = timerEnemyTimer
    Left = 64
  end
  object timerScore: TTimer
    OnTimer = timerScoreTimer
    Left = 128
  end
end