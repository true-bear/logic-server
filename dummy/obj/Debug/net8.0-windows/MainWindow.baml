   M S B A M L   `   `   `  ����  dummyClient    dummyClient.MainWindow   5   	   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  Chat Stress Client��5   	   $	��600��6$   $
��1000��61   .��5      � $��10q�6    � RowDefinitions 5   
   �� 5      $
��Auto �6   �� 5	      $
��Auto �6   �� 5      $��* �6   .+�5   
   ��  �� Orientation$ 
Horizontal=�6   $��0,0,0,10q�6.   $��0��6@   .+�5      �� $��Dummy Count:��6   $��Center=�6+   �� 5      -   5         ��Name$ txtDummyCount��5      $��60��6-   $	��5,0q�68   �� 5      -   5        $��Dummy Connect��5      $	��5,0q�6K   �� 5      -   5        $��Dummy Disconnect��5      $	��5,0q�6Q   �� 5      -   5        $��Dummy Chat Start��5      $	��5,0q�6P   �� 5      -   5        $��Dummy Chat Stop��5      $	��5,0q�6N   5      �� 5   
   $ 
Horizontal=�6   $��0,0,0,10q�6.   $��1��6@   .+�5      �� -   5        $��Single Connect��5      $	��5,0q�6M   �� 5      -   5        $��Single Disconnect��5      $	��5,0q�6S   �� 5      -   5        $��Single Chat��5      $	��5,0q�6G   �� 5      -	   5        $��Single Chat Stop��5      $	��5,0q�6P   5      � 5"   
   $��2��6    � ColumnDefinitions 5#      �� 5$      $��* �6#   �� 5%      $��* �6#   .+�5)      �� -
   5        $ txtLog��5)      $��0��6&   $��0,0,5,0q�66   " �� VerticalScrollBarVisibility$
 Auto=�5*       �� TextWrapping$
 Wrap=�5+       �� AcceptsReturn$
 True��5,       �� 
IsReadOnly$
 True��5-      �� 50      -   5        $ txtPacketLog��50      $��1��6,   $��5,0,0,0q�6<   $
 Auto=�51      $
 Wrap=�52      $
 True��53      $
 True��54      55      56      57      