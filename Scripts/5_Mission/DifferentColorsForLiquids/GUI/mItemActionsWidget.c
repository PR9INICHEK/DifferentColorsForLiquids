modded class ItemActionsWidget
{
	override protected void BuildCursor()
	{
		super.BuildCursor();
		
		// Добавляем пустую строку, чтобы отделить логи в этом файле от обычных
		//Print("\n");
		// Добавляем отметку, в каком файле и методе мы сейчас находимся
		//Print("ItemActionsWidget::BuildCursor() Called this method");
	
		// Пробуем новый метод изменения
		ItemBase itemInHands = ItemBase.Cast(m_EntityInHands);
		if (itemInHands)
			Print( "ItemActionsWidget::BuildCursor() itemInHands: " + itemInHands );
		//if (itemInHands)
			//Print( "ItemActionsWidget::BuildCursor() itemInHands.GetQuantity(): " + itemInHands.GetQuantity() );
		//if (itemInHands)
			//Print( "ItemActionsWidget::BuildCursor() itemInHands.IsLiquidContainer(): " + itemInHands.IsLiquidContainer() );
		
		if (itemInHands && itemInHands.GetQuantity() > 0 && itemInHands.IsLiquidContainer())
		{
			int liquid_type = itemInHands.GetLiquidType();
			Print( "ItemActionsWidget::BuildCursor() liquid_type: " + liquid_type );
			
			if (liquid_type == LIQUID_GASOLINE || liquid_type == LIQUID_WATER || liquid_type & GROUP_LIQUID_BLOOD)
			{
				// Ищем нужный виджет
				Widget widget = m_Root.FindAnyWidget("ia_item");
				Print( "ItemActionsWidget::BuildCursor() widget: " + widget );
				
				// Ищем строку состояния		
				Print( "ItemActionsWidget::BuildCursor() widget.FindAnyWidget('ia_item_quantity_pb'): " + widget.FindAnyWidget("ia_item_quantity_pb") );
				ProgressBarWidget progressBar = ProgressBarWidget.Cast( widget.FindAnyWidget("ia_item_quantity_pb") );
				Print( "ItemActionsWidget::BuildCursor() progressBar: " + progressBar );
				
				// Меняем цвет в ней
				if (liquid_type == LIQUID_GASOLINE)
					// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
					progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
				if (liquid_type == LIQUID_WATER)
					// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
					//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
					//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
					//progressBar.SetColor( 16772608 );	// 
					// Подобрал с помощью Colour picker в гугле
					progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
				if (liquid_type & GROUP_LIQUID_BLOOD)
					progressBar.SetColor(ARGB(255, 255, 0, 0));
			}
		}
		
		
		
		
		
		
		
		
		//! Меняем цвет полоски только для канистры
			// Делаем это здесь, так как только тут нам известно, что за предмет в руках у игрока
		//if ( m_EntityInHands && m_EntityInHands.GetType() == "CanisterGasoline" )
		//{
		
		// Попробуем по типу жидкости менять цвет
			// Получаем тип жидкости
			// Если то, что нам нужно, то производим замену
		
		// Объявляем эти переменные, чтобы вызвать GetItemQuantity()
			// TO DO Уточнить, почему мы не можем получить эти значения после вызова super.BuildCursor()
		/*int q_type = 0;
		int q_min, q_max = -1;
		float q_cur = -1.0;
		
		// Вызываем этот метод, чтобы получить значение q_cur, которое будем использовать ниже
		GetItemQuantity(q_type, q_cur, q_min, q_max);
		Print( "ItemActionsWidget::BuildCursor() q_cur: " + q_cur );
		
		if ( q_cur > 0)
		{
			// Меняем класс у canisterGasoline, чтобы выполнить GetLiquidType()
			ItemBase itemInHands = ItemBase.Cast(m_EntityInHands);
			Print( "ItemActionsWidget::BuildCursor() itemInHands: " + itemInHands );
			
			int liquid_type = itemInHands.GetLiquidType();
			Print( "ItemActionsWidget::BuildCursor() liquid_type: " + liquid_type );
			
			if (liquid_type == LIQUID_GASOLINE || liquid_type == LIQUID_WATER)
			{
				// Ищем нужный виджет
				Widget widget = m_Root.FindAnyWidget("ia_item");
				Print( "ItemActionsWidget::BuildCursor() widget: " + widget );
				
				// Ищем строку состояния		
				Print( "ItemActionsWidget::BuildCursor() widget.FindAnyWidget('ia_item_quantity_pb'): " + widget.FindAnyWidget("ia_item_quantity_pb") );
				ProgressBarWidget progressBar = ProgressBarWidget.Cast( widget.FindAnyWidget("ia_item_quantity_pb") );
				Print( "ItemActionsWidget::BuildCursor() progressBar: " + progressBar );
				
				// Меняем цвет в ней
				if ( liquid_type == LIQUID_GASOLINE )
					// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
					progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
				if ( liquid_type == LIQUID_WATER )
					// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
					//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
					//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
					//progressBar.SetColor( 16772608 );	// 
					// Подобрал с помощью Colour picker в гугле
					progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
			}
		}*/
		
		// TO DO Проверить, а надо ли сбрасывать на дефолтный
			// Если не сбрасывать, то при пустой строке остаётся цвет той жидкости, что была в контейнере
			
		/*
			// Ищем нужный виджет
			Widget widget = m_Root.FindAnyWidget("ia_item");
			Print( "ItemActionsWidget::BuildCursor() widget: " + widget );
			
			// Ищем строку состояния		
			Print( "ItemActionsWidget::BuildCursor() widget.FindAnyWidget('ia_item_quantity_pb'): " + widget.FindAnyWidget("ia_item_quantity_pb") );
			ProgressBarWidget progressBar = ProgressBarWidget.Cast( widget.FindAnyWidget("ia_item_quantity_pb") );
					
			Print( "ItemActionsWidget::BuildCursor() progressBar: " + progressBar );
			
			// Объявляем эти переменные, чтобы вызвать GetItemQuantity()
				// TO DO Уточнить, почему мы не можем получить эти значения после вызова super.BuildCursor()
			int q_type = 0;
			int q_min, q_max = -1;
			float q_cur = -1.0;
			
			// Вызываем этот метод, чтобы получить значение q_cur, которое будем использовать ниже
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			Print( "ItemActionsWidget::BuildCursor() q_cur: " + q_cur );
			
			if ( q_cur > 0)
			{	
				// Меняем класс у canisterGasoline, чтобы выполнить GetLiquidType()
				CanisterGasoline canisterGasoline = CanisterGasoline.Cast(m_EntityInHands);
				Print( "ItemActionsWidget::BuildCursor() canisterGasoline: " + canisterGasoline );
								
				if (canisterGasoline)
				{
					int liquid_type = canisterGasoline.GetLiquidType();
					Print( "ItemActionsWidget::BuildCursor() liquid_type: " + liquid_type );
					
					if ( liquid_type == LIQUID_GASOLINE )
						// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
						progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
					if ( liquid_type == LIQUID_WATER )
						// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
						//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
						//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
						//progressBar.SetColor( 16772608 );	// 
						// Подобрал с помощью Colour picker в гугле
						progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
				}
			}
			// Во всех остальных случаях сбрасываем на дефолтный
			else
			{
				progressBar.SetColor(-1);
			}
		*/
		//}	
	}	
		// Код ниже РАБОЧИЙ
		/*
		int health = -1;
		int q_type = 0;
		int q_min, q_max = -1;
		int q_chamber, q_mag = 0;
		float q_cur = -1.0;

		// item health
		health = GetItemHealth();
		SetItemHealth(health, "ia_item", "ia_item_health_mark", m_HealthEnabled);
		
		/*
		if ( m_EntityInHands )
			Print( "ItemActionsWidget::BuildCursor() m_EntityInHands.GetType(): " + m_EntityInHands.GetType() );
		*/
		
		// quantity
		//! weapon specific
		/*if (m_EntityInHands && m_EntityInHands.IsWeapon())
		{
			//GetWeaponQuantity(q_chamber, q_mag);
			SetWeaponQuantity(q_chamber, q_mag, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", m_QuantityEnabled);
			SetWeaponModeAndZeroing("ia_item_subdesc", "ia_item_subdesc_up", "ia_item_subdesc_down", true);
		}
		//! transmitter/PAS specific
		else if (m_EntityInHands && m_EntityInHands.IsTransmitter())
		{
			SetRadioFrequency(GetRadioFrequency(), "ia_item_subdesc", "ia_item_subdesc_up", "ia_item_subdesc_down", m_QuantityEnabled);
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			SetItemQuantity(q_type, q_cur, q_min, q_max, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", true);
		}
		//! Меняем цвет полоски только для канистры
			// Делаем это здесь, так как только тут нам известно, что за предмет в руках у игрока
		else if ( m_EntityInHands && m_EntityInHands.GetType() == "CanisterGasoline" )
		{
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			SetItemQuantity(q_type, q_cur, q_min, q_max, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", true);
			SetWeaponModeAndZeroing("ia_item_subdesc", "", "", false);
			
			/*
			// Код ниже скорее всего непросто будет переместить в нужный класс, так как нужно получать m_Root
			
			// Изменяем класс у m_EntityInHands на CanisterGasoline
			CanisterGasoline canisterGasoline;
			Print( "ItemActionsWidget::BuildCursor() Class.CastTo(canisterGasoline, m_EntityInHands): " + Class.CastTo(canisterGasoline, m_EntityInHands) );
			
			if ( Class.CastTo(canisterGasoline, m_EntityInHands) )
				// Если удалось поменять, то выполняем метод ниже
			// Проверяем тестовый метод у CanisterGasoline
			canisterGasoline.ChangeProgressBarColor();
			*/
			
			// ??? TO DO Возможно, что код ниже просто надо будет перенести в отдельный метод
			// Ищем нужный виджет
			/*Widget widget = m_Root.FindAnyWidget("ia_item");
			
			// Ищем строку состояния
			ProgressBarWidget progressBar;
			Class.CastTo(progressBar, widget.FindAnyWidget("ia_item_quantity_pb"));	
					
			Print( "ItemActionsWidget::BuildCursor() progressBar: " + progressBar );
			
			// Получаем текущий цвет строки состояния
			Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
			// Меняем цвет на оранжевый
			//progressBar.SetColor(Colors.ORANGE);
			
			// Меняем цвет только в зависимости от кол-ва жидкости и типа жидкости
			
				// Если пустая канистра, то ничего не меняем
			Print( "ItemActionsWidget::BuildCursor() q_cur: " + q_cur );
			/*
			if ( q_cur > 0)
				// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
				progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
			// Если равна нулю, то сбрасываем цвет на тот, что по умолчанию
			if ( q_cur == 0)
				progressBar.SetColor(-1);
			*/
			
			// Если канистра начинает заполняться, то меняем цвет, в зависимости от жидкости
			/*if ( q_cur > 0)
			{		
				CanisterGasoline canisterGasoline;
				Print( "ItemActionsWidget::BuildCursor() Class.CastTo(canisterGasoline, m_EntityInHands): " + Class.CastTo(canisterGasoline, m_EntityInHands) );
				//ItemBase canisterGasoline;
				//Print( "ItemActionsWidget::BuildCursor() Class.CastTo(canisterGasoline, m_EntityInHands): " + Class.CastTo(canisterGasoline, m_EntityInHands) );
				
				if ( Class.CastTo(canisterGasoline, m_EntityInHands) )
				{
					int liquid_type = canisterGasoline.GetLiquidType();
					Print( "ItemActionsWidget::BuildCursor() liquid_type: " + liquid_type );
					
					if ( liquid_type == LIQUID_GASOLINE )
						// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
						progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
					// ??? TO DO Речная вода действительно существует
						// Похоже, что нет
					if ( liquid_type == LIQUID_WATER )
						// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
						//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
						//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
						//progressBar.SetColor( 16772608 );	// 
						// Подобрал с помощью Colour picker в гугле
						progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
				}
			}
			// Во всех остальных случаях сбрасываем на дефолтный
			else
			{
				progressBar.SetColor(-1);
			}
			
			
			// Как изначально
			// progressBar.SetColor(-1);
			// Проверяем, что всё поменялось
			Print("\n");
			//Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
			if ( q_cur > 0)
				Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
			
		}
		else
		{
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			SetItemQuantity(q_type, q_cur, q_min, q_max, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", m_QuantityEnabled);
			SetWeaponModeAndZeroing("ia_item_subdesc", "", "", false);
		}
	
		SetItemDesc(m_EntityInHands, GetItemDesc(m_EntityInHands), "ia_item", "ia_item_desc");
		SetInteractActionIcon("ia_interact", "ia_interact_icon_frame", "ia_interact_btn_inner_icon", "ia_interact_btn_text");
		SetActionWidget(m_Interact, GetActionDesc(m_Interact), "ia_interact", "ia_interact_action_name");

		SetInteractActionIcon("ia_continuous_interact", "ia_continuous_interact_icon_frame", "ia_continuous_interact_btn_inner_icon", "ia_continuous_interact_btn_text");
		SetActionWidget(m_ContinuousInteract, GetActionDesc(m_ContinuousInteract), "ia_continuous_interact", "ia_continuous_interact_action_name");

		SetActionWidget(m_Single, GetActionDesc(m_Single), "ia_single", "ia_single_action_name");
		SetActionWidget(m_Continuous, GetActionDesc(m_Continuous), "ia_continuous", "ia_continuous_action_name");
		SetMultipleInteractAction("ia_interact_mlt_wrapper");
		SetMultipleContinuousInteractAction("ia_continuous_interact_mlt_wrapper");
		SetMultipleItemAction("ia_single_mlt_wrapper");
		SetMultipleContinuousItemAction("ia_continuous_mlt_wrapper");
	}
	
	/*protected void SetItemQuantity(int type, float current, int min, int max, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled )
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if(enabled)
		{
			ProgressBarWidget progressBar;
			TextWidget textWidget;
			Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
			Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));

			//check for volume vs. count and display progressbar or "bubble" with exact count/max text
			switch (type)
			{
				case QUANTITY_HIDDEN :
					progressBar.Show(false);
					textWidget.Show(false);
					textWidget.GetParent().Show(false);
					break;
				case QUANTITY_COUNT :
					if(max > 1 || current > 1)
					{
						string qty_text = string.Format("%1/%2", Math.Round(current).ToString(), max.ToString());
						progressBar.Show(false);
						textWidget.SetText(qty_text);
						textWidget.Show(true);
						textWidget.GetParent().Show(true);
						break;
					}
					else
					{
						progressBar.Show(false);
						textWidget.Show(false);
						textWidget.GetParent().Show(false);
						break;
					}
				case QUANTITY_PROGRESS :	
					textWidget.Show(false);
					progressBar.SetCurrent(current);
					progressBar.Show(true);
					textWidget.GetParent().Show(true);
					break;
			}
			widget.Show(true);
		}
		else
			widget.Show(false);	
	}*/
	
}