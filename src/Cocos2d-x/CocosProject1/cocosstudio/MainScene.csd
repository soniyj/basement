<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="background" CanEdit="False" ActionTag="-57860470" Tag="3" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-88.0000" RightMargin="-88.0000" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.2000" ScaleY="1.2000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.1833" Y="1.0000" />
            <FileData Type="Normal" Path="Assets/BackgroundImage/background.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="leftPanel" ActionTag="-842848207" Tag="4" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" RightMargin="768.0000" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="192.0000" Y="640.0000" />
            <Children>
              <AbstractNodeData Name="btnPlay" ActionTag="1703105846" Tag="11" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="26.0000" RightMargin="26.0000" TopMargin="38.8000" BottomMargin="525.2000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="110" Scale9Height="54" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="140.0000" Y="76.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="96.0000" Y="563.2000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8800" />
                <PreSize X="0.7292" Y="0.1187" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="play-pressed.png" Plist="" />
                <NormalFileData Type="Normal" Path="play.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnPause" ActionTag="-751178032" Tag="12" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="26.0000" RightMargin="26.0000" TopMargin="122.0000" BottomMargin="442.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="110" Scale9Height="54" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="140.0000" Y="76.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="96.0000" Y="480.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7500" />
                <PreSize X="0.7292" Y="0.1187" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="pause-pressed.png" Plist="" />
                <NormalFileData Type="Normal" Path="pause.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="balloon" ActionTag="-1508548798" Tag="13" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="11.0000" RightMargin="11.0000" TopMargin="217.2000" BottomMargin="242.8000" ctype="SpriteObjectData">
                <Size X="170.0000" Y="180.0000" />
                <Children>
                  <AbstractNodeData Name="populationLabel" ActionTag="-1768550147" Tag="15" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="27.4000" RightMargin="20.6000" TopMargin="33.5000" BottomMargin="123.5000" FontSize="20" LabelText="Population" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="122.0000" Y="23.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="88.4000" Y="135.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="13" G="159" B="0" />
                    <PrePosition X="0.5200" Y="0.7500" />
                    <PreSize X="0.7176" Y="0.1278" />
                    <FontResource Type="Normal" Path="Courier New Bold.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="populationCount" ActionTag="615380206" Tag="16" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="81.9000" RightMargin="75.1000" TopMargin="62.3000" BottomMargin="94.7000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="13.0000" Y="23.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="88.4000" Y="106.2000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="13" G="159" B="0" />
                    <PrePosition X="0.5200" Y="0.5900" />
                    <PreSize X="0.0765" Y="0.1278" />
                    <FontResource Type="Normal" Path="Courier New Bold.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="generationLabel" ActionTag="947315421" Tag="17" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="27.4000" RightMargin="20.6000" TopMargin="96.5000" BottomMargin="60.5000" FontSize="20" LabelText="Generation" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="122.0000" Y="23.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="88.4000" Y="72.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="13" G="159" B="0" />
                    <PrePosition X="0.5200" Y="0.4000" />
                    <PreSize X="0.7176" Y="0.1278" />
                    <FontResource Type="Normal" Path="Courier New Bold.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="generationCount" ActionTag="-1321237311" Tag="18" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="81.9000" RightMargin="75.1000" TopMargin="127.1000" BottomMargin="29.9000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="13.0000" Y="23.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="88.4000" Y="41.4000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="13" G="159" B="0" />
                    <PrePosition X="0.5200" Y="0.2300" />
                    <PreSize X="0.0765" Y="0.1278" />
                    <FontResource Type="Normal" Path="Courier New Bold.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="96.0000" Y="332.8000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5200" />
                <PreSize X="0.8854" Y="0.2813" />
                <FileData Type="Normal" Path="Assets/SpriteImages/balloon.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="microscope" ActionTag="-1103891018" Tag="14" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="38.0000" RightMargin="38.0000" TopMargin="405.0000" BottomMargin="21.0000" ctype="SpriteObjectData">
                <Size X="116.0000" Y="214.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="96.0000" Y="128.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.2000" />
                <PreSize X="0.6042" Y="0.3344" />
                <FileData Type="Normal" Path="Assets/SpriteImages/microscope.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="0.5000" />
            <Position Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.5000" />
            <PreSize X="0.2000" Y="1.0000" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="rightPanel" ActionTag="-1391526464" Tag="5" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="192.0000" RightMargin="0.0001" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="767.9999" Y="640.0000" />
            <Children>
              <AbstractNodeData Name="gridNode" ActionTag="144475588" Tag="8" IconVisible="True" LeftMargin="376.0004" RightMargin="391.9996" TopMargin="317.3333" BottomMargin="322.6667" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="376.0004" Y="322.6667" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4896" Y="0.5042" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Grid.csd" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="575.9999" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6000" Y="0.5000" />
            <PreSize X="0.8000" Y="1.0000" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>