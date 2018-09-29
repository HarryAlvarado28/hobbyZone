class CreateFarmers < ActiveRecord::Migration[5.2]
  def change
    create_table :farmers do |t|
      t.string :name
      t.string :email
      t.integer :phone_number
      t.string :image

      t.timestamps
    end
  end
end
